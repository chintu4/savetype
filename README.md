# savetypeing
this repo code  and exe in linux that just help you to save your keystroke for your repeated or regular commands
## installation
* there is a code and executable called q 
* save q in /usr/bin
## os supported
* linux
* windows(just change the url in the source and compile)
## usage 
* first try to save a command 
* q w key "value"
#### example:
* q w code "vim /home/{user}/p.c"
* directly call it from any where 
format:
* q key
##### example 
* q code
* vim gets opened 
## how fast is it 
You can see the results i got
* real	0m0.005s
* user	0m0.000s
* sys	0m0.004s

# issues
* currently cd command is not working
* you cannot place a value "cd /home/{user}" instead can place "vim /home/{user}"
* besure each user have his own key value saved in /home/{user}/Documents/c.txt
* do not manual try to c.txt
