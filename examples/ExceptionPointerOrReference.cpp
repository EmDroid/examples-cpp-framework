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
catch (const TheException * const e)      // Catch the exception by pointer.
{
    e->Fail();
    delete e;  // Destroy the exception thrown by pointer.
}
