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
    @internal

    @file

    Global new and delete operators (inline methods).

    @author Emil Maskovsky
*/


/* static */ MX_INLINE void * mx::AllocOperatorsImplementation::New(
        const Size iMemoryBlockSize,
        const Debug::Checkpoint & xFileInfo,
        const bool MX_UNUSED(bVectorAlloc))
{
    return Memory::AllocateImpl(iMemoryBlockSize, xFileInfo);
}


/* static */ MX_INLINE void mx::AllocOperatorsImplementation::Delete(
        void * const pMemoryBlock,
        const bool MX_UNUSED(bVectorFree))
{
    Memory::Free(pMemoryBlock);
}


/* EOF */