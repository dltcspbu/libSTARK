#check if emscripten exists and install it if not found
if ! command -v emmake || ! command -v emcmake; then
  echo 'Could not find emscripten, installing...'
  EMSDK_PATH=../emsdk/
  EMSCRIPTEN_PATH="$EMSDK_PATH"fastcomp/emscripten
  if [ ! -d "$EMSDK_PATH" ]; then
    git clone https://github.com/emscripten-core/emsdk "$EMSDK_PATH"
  fi
  echo ./"$EMSDK_PATH"emsdk install latest
  eval ./"$EMSDK_PATH"emsdk install latest
  eval ./"$EMSDK_PATH"emsdk activate latest
  eval source ./"$EMSDK_PATH"/emsdk_env.sh
fi

#create build dir
if [ ! -d "_build" ]; then
    mkdir _build
fi
cd _build

#run cmake with emscripten
emcmake cmake ..

#set threads number while compilation
input=../threads_num.txt
if [ -f "$input" ]; then
  while IFS= read -r line || [ -n "$line" ]; do
    echo "LINE: $line"
    threads_num="$line"
  done < "$input"
else
  threads_num=2
fi

#compile
emmake make -j"$threads_num"

#put command line arguments to the script
python3 ../put_arguments.py

cd tinyram/stark-tinyram

#create html file that will run the script
PAGE=index.html
if [ -f "$PAGE" ]; then
    rm "$PAGE"
fi
echo -n "<script src='stark-tinyram.js'></script>" >> "$PAGE"

#run server at localhost:8000
python3 -m http.server