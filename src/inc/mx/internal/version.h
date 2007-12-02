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


#ifndef MXCPP_VERSION_H_INLUDE_GUARD
#define MXCPP_VERSION_H_INLUDE_GUARD

#define MX_VERSION_MAJOR      0
#define MX_VERSION_MINOR      1
#define MX_VERSION_INTERFACE  0
#define MX_VERSION_BUILD      1

#define MX_STR_VERSION  "0.1.0.1\0"
#define MX_NUM_VERSION  0, 1, 0, 1

#define MX_PROD_NUM_VERSION  MX_NUM_VERSION
#define MX_PROD_STR_VERSION  "0.1\0"

#define MX_COMPANYNAME     "Emil Maskovsky\0"
#define MX_LEGALCOPYRIGHT  "© 2007 Emil Maskovsky\0"
#define MX_PRODUCTNAME     "Demo C++ Framework\0"

#define MX_VERSION_ID                                      \
    MX_VERSION_MAJOR * 1000000 + MX_VERSION_MINOR * 100000 \
    + MX_VERSION_INTERFACE * 1000 + MX_VERSION_BUILD

#endif /* MXCPP_VERSION_H_INLUDE_GUARD */


/* EOF */
