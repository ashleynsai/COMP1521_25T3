# Files



### Reading and writing to a file:  *demo in `append_line.c`*

7. Write a C program, ```append_line.c```, which is given one command-line argument, the name of a file, and which reads a line from ```stdin``` and appends it to the specified file.

   - What does ```fopen``` do? What are its parameters? What is the return value?

   

   - ###### What are some circumstances when ```fopen``` returns null?

   

   How do you print the specific reason that caused `fopen` to return `NULL`?  

   *demo in `append_line.c`*



8. Why should you not use ```fgets``` or `fputs` with binary data?

```
Strings are ended by null terminators, which is the value 0 and binary data can have 0s for other reasons. 

fgetc 
```





### File metadata

13. Consider the following (edited) output from the command `ls -l ~cs1521`:

    ```
    drwxr-x--- 11 z5420403 cs1521 4096 Aug 27 11:59 17s2.work
    drwxr-xr-x  2 cs1521 cs1521 4096 Aug 20 13:20 bin
    -rw-r-----  1 cs1521 cs1521   38 Jul 20 14:28 give.spec
    drwxr-xr-x  3 cs1521 cs1521 4096 Aug 20 13:20 lib
    drwxr-x--x  3 cs1521 cs1521 4096 Jul 20 10:58 public_html
    drwxr-xr-x 12 cs1521 cs1521 4096 Aug 13 17:31 spim
    drwxr-x---  2 cs1521 cs1521 4096 Sep  4 15:18 tmp
    lrwxrwxrwx  1 cs1521 cs1521   11 Jul 16 18:33 web -> public_html
    ```

    1. Who can access the `17s2.work` directory?

       ```
       user and groups
       ```

    2. What operations can a typical user perform on the `public_html` directory?

       ```
       execute
       ```

    3. What is the file `web`?

       ```
       symlink
       ```

    4. What is the difference between `stat("sym", &info)` and `lstat("web", &info)`?
       (where `info` is an object of type `(struct stat)`)

       ```
       stat will give metadata of the file the symlink is pointing to, and lstat will give metadata of the symlink file itself
       ```



15. Write a C program, `print_perms.c`, which is given 1+ command-line arguments which are the pathnames of files.

    Print to stdout the permissions in octal form.

    How would we change the octal into something more readable like "rwxr-xr-x"