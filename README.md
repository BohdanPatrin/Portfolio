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
As you can see, the fastest operation is subtraction for int, not the expected addition. This may be due to the use of optimization algorithms for multiplication.<br/>
•***Simulation model of the CPU***<br/>
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
Then I entered the summa command and, as we can see, it was executed, and the result was was written to the first register. After that, I wanted to put a value in the third register, which is too large for the int type, and I got an error. When the execution of commands, you can see changes in the values of the status register, the counter and clock counters, so the program is executing correctly.<br/>
•***Interaction of distributed processes through the socket mechanism***<br/>
**Task statement**<br/>
1) Develop a data exchange protocol for your variant: a data exchange script and its commands (a message is transmitted via a socket, and what to do with it is determined by the commands).<br/>
2) Develop two programs, the so-called client program (hereinafter referred to as the client) and the server program (hereinafter referred to as the server). These two programs, running on different workstations (nodes) of the network, should exchange commands according to the protocol developed by the author, using the socket mechanism in the TCP/IP profile.<br/>
3) A response to erroneous commands must be provided.<br/>
4) The destination port number should be selected as follows: #_port = 1025 + #_variant.<br/>
5) All variants must support a command named Who, in response to which the server provides information about the author and the number and short name of the variant.<br/>
6) The client and the server must make a record in the system log (text file) for each sent/received socket message about: time of validity, message command(s).<br/>
7) The format of socket messages is as follows: <br/>  
 Header: Data<br/>
Header format and field sizes:<br/>
 Header length - 1 byte<br/>
Commands - up to 255 bytes<br/>
Of course, if there are no commands in the header, there should still be one byte of header length (and equal to 1). As a rule, a message will contain one command (optional elements in [...]). The command may have operands, in which case the syntax of such commands is up to you.<br/>
My variant:<br/>
Guess the 4-digit number game: The user on the client guesses a 4-digit integer that is stored on the server. 4 digits are sent from the client, to which the server responds with the number of correct digits. The client can give up and then the server reveals the guessed number. The user on the client can choose the method of setting attempts: entering them in a dialog or automatically generating random 4-digit numbers in a given amount.<br/>
***Results of execution***<br/>
Сlient program:<br/> ![image](https://github.com/BohdanPatrin/Portfolio/assets/127937644/7596341f-32be-4f12-aab8-02dd72e26fc9)<br/>
Server program:<br/> ![image](https://github.com/BohdanPatrin/Portfolio/assets/127937644/b386b52d-72b6-4cc7-a618-0abad3ca835b)<br/>
First, I launched the server, then the client. After the connection, I entered the command "start game" and chose the method of setting the number by generation. The number 6589 was generated. Since the number 6569 was given, the number of correct numbers was 3, which the program displayed. After that, I chose to enter the number, entered 6569, and the program displayed a message that I had guessed the number.  Then I entered the who command on the server and the IP address of the client was displayed (since both programs are running on the same device, the address is 127.0.01). After that, I entered the command end session on the client and the program stopped working.<br/>
Logging:<br/> ![image](https://github.com/BohdanPatrin/Portfolio/assets/127937644/9f72ed55-d354-42b9-a278-bb406c6f5287) <br/>
So, the program runs as intended.<br/>
