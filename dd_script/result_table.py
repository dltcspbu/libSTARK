import pandas as pd
f=open("result.txt")
dic = {'First param': [], 'Second param': [],'Witness time': [], 'Prover time': [], 'Verifier time': []} 
for line in f:
	if "first param" in line:
		value1=len(line) - (line[::-1]).find('t')
		dic['First param'].append(line[value1:len(line)-1])	
	if "second param" in line:
		value1=len(line) - (line[::-1]).find('s')
		dic['Second param'].append(line[value1:len(line)-1])
	if "Constructing APR (ACSP) witness:" in line:
		value1=len(line) - (line[::-1]).find('(')
		value2=len(line) - (line[::-1]).find(')')
		dic['Witness time'].append(line[value1:(value2-1)])
	if "Prover time" in line:
		value1=len(line) - (line[::-1]).find('=')
		value2=len(line) - (line[::-1]).find('|')
		dic['Prover time'].append(line[value1:(value2-1)])
	if "Verifier time" in line:
		value1=len(line) - (line[::-1]).find('=')
		value2=len(line) - (line[::-1]).find('|')
		dic['Verifier time'].append(line[value1:(value2-1)])
df = pd.DataFrame(data=dic)
df.to_csv('storage.csv')


