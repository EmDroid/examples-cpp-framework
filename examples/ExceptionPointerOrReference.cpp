try
{
    // Doing something ...
    throw TheException({parameters});  // Throw the exception by value.
    // Doing something ...
}
catch (const TheException & e)      // Catch the exception by reference.
{
    e.Fail();
}

try
{
    // Doing something ...
    throw new TheException({parameters});  // Throw the exception by pointer.
    // Doing something ...
}
catch (TheException * e)      // Catch the exception by pointer.
{
    /*
        Warning: TheException is not const, because it is later destroyed
                 using delete operator.

        Warning: Do not catch by 'const' pointer ('* const e'), because it
                 causes loss of type information under some compilers
                 (Borland C++ known so far).

        Warning: For above reasons, it is better to use throw-by-value
                 and catch-by-reference for most applications, unless
                 there are very good reasons to throw by pointer.
                 (you even do not need to bother about destruction of
                 exceptions caught by reference)
    */
    e->Fail();
    delete e;  // Destroy the exception thrown by pointer.
}
