# Portfolio
•***Comparison of the speed of operations with different types of data***<br/>
**Task statement**
It is necessary to develop a program that measures the number of basic operations (commands) performed per second by a particular PCS (computer + OS + Programming System). Measuring a "pure" CPU instruction is not required (as is the case in real software systems that are typically developed in high-level languages, often even platform-independent ones) and is actually meaningless.<br/>
The basic set of operations is sufficient to include addition, subtraction, multiplication, and division operations for each of the basic data types (character, integer variants, real, etc., as available in a particular language or programming system). Other operations, commands, and types are optional. For example, for C/C++, you need to take the types char, int, long, float, and double. Given that all types of processors are characterized by hardware combining the addition and subtraction commands into one command by changing the sign of one of the operands accordingly (but for ease of coding at the command set level, these operations appear as separate commands), you cannot measure only one of these two commands.<br/>
The measurement accuracy is 2%. It is enough to assume that for short operations (addition/subtraction for whole words), the number of operations approximately corresponds to the clock frequency of the computer processor. Take 2% of this value, and this value will be the ± error between the same results for a series of program runs. For example, at a clock frequency of 2 GHz, 2% is equal to 40 MHz, or approximately 40 million short cycles per second; therefore, the error between the results of the same name is ±40 million cycles per second. That is, the fastest result (for example, for an addition operation) is taken as 100%, and a similar operation (let's say subtraction) may lag behind addition by 40 million operations.<br/>
The program must demonstrate measurement stability for a series of runs. It should be borne in mind that when working on the MS Windows platform, the system may begin to swap during a test measurement, so in this case, neighboring measurements in the series may differ by an order of magnitude. Such runs should be excluded from consideration.<br/>
The results should be presented in a tabular form, showing for each test:<br/>
1. the name of the team/operation,<br/>
2. data type/format,<br/>
3. the number of operations per second (do not display extra digits in the mantissa for a given accuracy),<br/>
4. a line chart of the speed value in percentage terms relative to the fastest command/operation, which is taken as 100%,<br/>
5. percentage value (can be rounded to the nearest whole number).<br/>
***Results of execution***<br/>
![image](https://github.com/BohdanPatrin/Portfolio/assets/127937644/4b75de3b-4eec-4029-86ba-542fb0175b77)
As you can see, the fastest operation is subtraction for int, not the expected addition. This may be due to the use of optimization algorithms for multiplication.
•***Simulation model of the CPU***
**Task statement**<br/>
It is necessary to develop a software model of the processor and implement its simulation (i.e., computer) model.The Contractor will be offered an individual variant, which will determine the specific:<br/>
1) addressability of the processor (1-, 2- or 3-address, or the number of operands);<br/>
2) processor bit rate (data highway);<br/>
3) mandatory processor instruction to be implemented;<br/>
Must be implemented:<br/>
1) placement of the interpreted program in a text file (for example, one line = one command);<br/>
2) at least 2 commands (one of them is to write a value to a register/stack/OP, others are specified by a variant);<br/>
3) bitwise representation for operands/registers, possibly for some variants with byte grouping variants with byte grouping of bits.<br/>
RAM shall be represented in 16-bit format;<br/>
4) fixation in the status register of at least the sign of the command execution result;<br/>
5) clockwise execution of commands (for example, the 1st clock is the entry of the command into the command register, 2nd cycle - interpretation of operands, 3rd cycle - execution of the operation and recording the result).<br/>
*My variant:*<br/>
Addressability of the processor: 2-address<br/>
Bit depth of registers: 26-bit<br/>
Processor commands:<br/>
Each byte of the 1st operand of the command is treated as a digit from 0 to 9 (unsigned). The command returns the sum of these byte-digits taken modulo the number specified by the 2nd operand, represented in:<br/>
- the command directly or a register for stackless implementation;<br/>
- the top of the stack in a stacked implementation of the operand placement.<br/>
It is necessary to take into account:<br/>
- register/stack bits should be displayed with byte-by-byte breakdown;<br/>
- in variants with an incomplete byte (18-, 20-, 22-bit operands), such a byte is supplemented with leading zeros;<br/>
- provide a command format with a number in the operand in literal form (with digits 0...9 for the corresponding bytes)<br/>
***Results of execution***<br/>
![image](https://github.com/BohdanPatrin/Portfolio/assets/127937644/e9d44948-ad26-47a1-b9d6-20e602045885)<br/>
![image](https://github.com/BohdanPatrin/Portfolio/assets/127937644/63b7632b-60d1-470e-8fe5-292ae618ec7d)<br/>
First, I entered the value 10005 in the first register, then 17 in the second register.
Then I entered the summa command and, as we can see, it was executed, and the result was was written to the first register. After that, I wanted to put a value in the third register, which is too large for the int type, and I got an error. When the execution of commands, you can see changes in the values of the status register, the counter and clock counters, so the program is executing correctly.

