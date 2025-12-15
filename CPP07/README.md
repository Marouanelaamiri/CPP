what are templets, what problem do they solve ? , can temples fails ? 

a templet is not a funtion its a blueprint that tells the compiler how to write a function
its like im telling the compiler that i dont know the data type yet , lets call it T
and at compile time(at the linker stage to be exact) ,the compiler change the data type
accordinly, can they fail u ask , ofc they can but they fail at compile time , no crash.
cases of failure : if we have a class "dog" and we didnt overload the > operator ,
a compile error happend , or at linker stage if we didnt implment the template on
the header file (the compiler needs to se the template implemnetaion on hpp file, it
need the entire source code of the template so it can copy-past and modify it accordinly)
what problem they solve u ask , they solve DRY problem .