Hi! Here are instructions for running my code.
I'm sorry that I didn't make a better user interface,
I was running out of time.

I have included 2 small test files. They "work" on both,
although one of them fails to recognize a key mistake (ddfs1.txt).
The key mistake is that when the code runs on ddfs1.txt, the 
earliest flight shortest path function allows a flight from NewYork
to Boston even though the flight leaves NY before the flight from
Boston Arrives.

The ddfs2.txt file fixes this by changing the times so that the
schedule works -- the flight from Boston to NY comes in before
the flight from NY to Chicago leaves --> producing a good output
in the correct scenario.

In order to change the input file, you have to go into the main
and change the input file (currently on line 18). Once again, 
I'm sorry that I didn't make the user interface better.

From there you should be able to just compile with make (or
make all) and then run main (./main).

There may be some debug text (unless I had time to remove it).
But I tried to make the differentiation between debug text and 
actual output by preceeding real output with lines like this:

================ FROM MAIN FUNCTION ======================
============== small description of which function is running =========
//output here


The code is not perfect, but I worked really hard on it and I hope that 
you can see the effort that I put in. I hope you like it. Thanks!

Sincerely,
Junhson
