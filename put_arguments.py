from tempfile import mkstemp
from shutil import move
from os import fdopen, remove

def replace(file_path, pattern, subst):
    #Create temp file
    fh, abs_path = mkstemp()
    with fdopen(fh,'w') as new_file:
        with open(file_path) as old_file:
            for line in old_file:
                new_file.write(line.replace(pattern, subst))
    #Remove original file
    remove(file_path)
    #Move new file
    move(abs_path, file_path)

script_path = 'tinyram/stark-tinyram/stark-tinyram.js'
args_pattern = 'var arguments_ = []'
args = "var arguments_ = ['collatz.asm', '-s1', '-t1']"

replace(script_path, args_pattern, args)