# OS-Assignment-2
*Authors:</br>
  Inon Sinn - 209632009</br>
  Israel Yacovowich - 212403679</br>*
  
 ## About
 This Assignment had a total of 8 questions divided into two Parts: A and B.</br>
 In Part A we deepend our understanding of the linux commands tee(1) and nc(1)</br>
 In Part B we Created our own shell and implemet command pipes and more </br>
 
 *Part A*
 * 1. Writing our own version of tee(1), without the arguments
 * 2. Recreating nc(1) but only for TCP client/server
 
 *Part B*
 * 1. Implement The dir(1) command
 * 2. Implement copy that gets 2 files and copies from one to the other
 * 3.
 * 4.
 * 5.
 * 6.

  ## Refernces
  Question A.1 - [Example of using getline(3)](https://linuxhint.com/read-lines-stdin-c-programming/)</br>
  Question A.2 - [TCP Client/server](https://www.geeksforgeeks.org/tcp-server-client-implementation-in-c/)</br>
  Question B.1 - [Video about list files in a directory](https://www.youtube.com/watch?v=j9yL30R6npk&t=291s&ab_channel=CodeVault)</br>
  
  ## Scripts
  As the scripts using scipt(1) places everything in the log file, including linefeeds and backspaces. This is not what the naive user expects.</br>
  I will write it orderly and add the actual script result in a spoiler warning(see below)</br>
  
 **Part A.1**
 
 Input: ./mytee test1.txt</br>
        Test 1 for the script</br>
 Output: Test 1 for the script
 
 Input:/mytee test1.txt test2.txt test3.txt</br>
       Will write to all 3 files
 Output: Will write to all 3 files
 
 <details>
  <summary>Spoiler</summary>

  ````markdown
Script started on 2022-11-30 23:13:42+02:00 [TERM="xterm-256color" TTY="/dev/pts/0" COLUMNS="96" LINES="27"]

]0;inon@inon-VirtualBox: ~/Desktop/Opperating Systems Course/Assignment 2[01;32minon@inon-VirtualBox[00m:[01;34m~/Desktop/Opperating Systems Course/Assignment 2[00m$ exit./mytee test1.txt test2.txt test3.txt[A

]0;inon@inon-VirtualBox: ~/Desktop/Opperating Systems Course/Assignment 2[01;32minon@inon-VirtualBox[00m:[01;34m~/Desktop/Opperating Systems Course/Assignment 2[00m$ [C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[K



[K[A[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C

Test 1 forh  te   he script

Test 1 for the script

]0;inon@inon-VirtualBox: ~/Desktop/Opperating Systems Course/Assignment 2[01;32minon@inon-VirtualBox[00m:[01;34m~/Desktop/Opperating Systems Course/Assignment 2[00m$ ./mytee test1.txtexit[K./mytee test1.txtexit[K./mytee test1.txt test2.txt test3.txt[A

]0;inon@inon-VirtualBox: ~/Desktop/Opperating Systems Course/Assignment 2[01;32minon@inon-VirtualBox[00m:[01;34m~/Desktop/Opperating Systems Course/Assignment 2[00m$ [C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[K



[K[A[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C test2.txt test3.txt

Will write to all 3 files

Will write to all 3 files

]0;inon@inon-VirtualBox: ~/Desktop/Opperating Systems Course/Assignment 2[01;32minon@inon-VirtualBox[00m:[01;34m~/Desktop/Opperating Systems Course/Assignment 2[00m$ exit

exit



Script done on 2022-11-30 23:14:19+02:00 [COMMAND_EXIT_CODE="0"]


````  
  
</details> 

**Part A.2**

![](https://github.com/Inon-Sinn/OS-Assignment-2/blob/master/Recordings/Part%20A.2%20version%203.gif)

**Part B.1**

**Part B.2**

**Part B.3**

**Part B.4**

**Part B.5**

**Part B.6**
