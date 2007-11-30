/*
    Copyright (C) 1998-2007 Emil Maskovsky

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
    implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/


/**
    @file

    Global new and delete operators (inline methods).

    @author Emil Maskovsky
*/


MX_INLINE void * operator new (
        const mx::Size iMemoryBlockSize,
        const char * const sFileName,
        const mx::Size iFileLine)
{
    return mx::OperatorNewImplementation(
            iMemoryBlockSize, sFileName, iFileLine);
}


MX_INLINE void * operator new[] (
        const mx::Size iMemoryBlockSize,
        const char * const sFileName,
        const mx::Size iFileLine)
{
    return mx::OperatorNewImplementation(
            iMemoryBlockSize, sFileName, iFileLine, true);
}


MX_INLINE void operator delete (
        void * pMemoryBlock)
{
    mx::OperatorDeleteImplementation(pMemoryBlock);
}


MX_INLINE void operator delete[] (
        void * pMemoryBlock)
{
    mx::OperatorDeleteImplementation(pMemoryBlock, true);
}


#ifdef MXCPP_FIX_DELETE_PARAMS_LIKE_NEW

// We do not require this, bu some compilers (MSVC) must have defined
// delete operator with same parameters like new.


MX_INLINE void operator delete (
        void * pMemoryBlock,
        const char * const MX_UNUSED(sFileName),
        const mx::Size MX_UNUSED(iFileLine))
{
    mx::OperatorDeleteImplementation(pMemoryBlock);
}


MX_INLINE void operator delete[] (
        void * pMemoryBlock,
        const char * const MX_UNUSED(sFileName),
        const mx::Size MX_UNUSED(iFileLine))
{
    mx::OperatorDeleteImplementation(pMemoryBlock, true);
}


#endif // MXCPP_FIX_DELETE_PARAMS_LIKE_NEW


/* EOF */
