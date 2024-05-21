# Intructions to run the program: 

- Clone the repository
- Write *make bonus* on pwd trought your terminal to run Makefile
- Create a file to be read by your program. i.e. file_name.txt and write some lines. ie: first line 1\n line 12\n line 13\ line 3
- Ejecute the program. Write *.\make_bonus file_name cat "grep 3" "grep 1" outfile
- A new file *outfile* will be created with the content of file_name.txt precessed by the commands.

- You can use as many commands as you want.
- That would be the same as use grep 3 < file_name.txt | grep 1 > outfile
- Here_doc option is available using:
   .\make_bonus here_doc eof cat "grep 3" "grep 1" outfile
    where eof any word to finish entering lines from here_doc.
    it is equivalent to:
   grep 3 << eof | grep 1 >> outfile
- If outfile does not exist, it will be created.
