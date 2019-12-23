import subprocess
range1 =[5,6,7,8,9,10] #first parametr
range2= [5,10,20,40,60,80,120] #second parametr
res=open("result.txt", 'a')
for t in range1:
	for s in range2:
		f=open("condoub.txt", 'w') #create .txt with console duplication for parcing
		value1='-t'+str(t)  
		value2='-s'+str(s)
		subprocess.call(["./stark-tinyram", "examples-tinyram/collatz.asm", value1, value2], 			stdout=f)
		#all info after finish tinyRAM with params t,s now in condoub.txt
		#Here starting parcing condoub.txt to take information about time
		res.write('first param'+value1+'\n')
		res.write('second param'+value2+'\n')
		f.close()
		f=open("condoub.txt", 'r')
		for line in f:
			if "Constructing APR (ACSP) witness:" in line:
				res.write(line)
			if "Verifier decision:" in line:
				res.write(line)
			if "Prover time" in line:
				res.write(line)
			if "Verifier time" in line:
				res.write(line)
			if "Total IOP length" in line:
				res.write(line)
			if "Total communication complexity (STARK proof size)" in line:
				res.write(line)
			if "Query complexity" in line:
				res.write(line)
		res.write('----------------------------------------------'+'\n')	
