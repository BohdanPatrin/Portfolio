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
