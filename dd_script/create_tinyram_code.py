def create_tinyram_code(cash1, cash2, value):
	code = ""
	#create asm opcode file 
	#here add data to register
	#print(cash1, cash2, value)
	code += "MOV r1 r0 " + str(cash1) + ";" #1 string
	code += "MOV r2 r0 " + str(cash2) + ";" #2 string
	code += "MOV r3 r0 " + str(value) + ";" #3 string
	#add flag for answer
	code += "MOV r8 r0 1;" #4 string
	#here add total cash =cash1+cash2=r4
	code += "ADD r4 r1 r2;" #5 string
	#here check that cash1>=value 
	code += "CMPAE r0 r1 r3;" #6 string
	#if not compare jump to end(where answer), last param is number of string where answer is
	code += "CNJMP r0 r0 16;" #7 string
	#else make change
	#here r5=cash1-value=new cash1
	code += "SUB r5 r1 r3;" #8 string
	#here cash2+value=r6=new cash2
	code += "ADD r6 r2 r3;" #9 string
	#here new toal cash=new cash1+new cash2
	code += "ADD r7 r5 r6;" #10 string
	#here check that total cash old=total cash n
	code += "CMPAE r0 r4 r7;" #11 string
	#if not compare jump to end(where answer), last param is number of string where answer is
	code += "CNJMP r0 r0 16;" #12 string
	#else change value of flag
	code += "MOV r8 r0 0;" #13 string
	#and store new cash1 value into 1 memory
	code += "STOREW r5 r0 1;" #14 string
	#and store new cash2 value into 2 memory
	code += "STOREW r6 r0 2;" #15 string
	#this is numberstring to jump and answer
	code += "ANSWER r0 r0 r8" #16 string
	return code



 

