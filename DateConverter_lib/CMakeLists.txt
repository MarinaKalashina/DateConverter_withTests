project(DateConverter)

set(HEADER_FILES
        Gregorian.h
        Julian.h
        )

set(SOURCE_FILES
        Gregorian.cpp
        Julian.cpp
        )

add_library(DateConverter_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})