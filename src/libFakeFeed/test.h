#pragma once

#include <iostream>
#include "QDebug"
#include "QProcess"
#include "QStringList"
#include "QString"
#include "QObject"
#include <iostream>

#include <module.h>

class Test {
    public:
        void initiateTest ();
        void testManageDevice ( Module& m );
        void testFindOriginalCam ();
        void testStream ();
};
