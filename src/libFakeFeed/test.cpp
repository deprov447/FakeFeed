#include "test.h"

void
Test::initiateTest ()
{
    Test t;
    Module m;
    t.testManageDevice( m );
    qDebug() << "testManageDevice : passed";
}

void
Test::testManageDevice ( Module& m )
{
    m.manageDevice( "uvcvideo", true );
    qDebug() << "UVCvideo module removed";
    bool did;
    std::cin >> did;
    if (!did)
        return;
    m.manageDevice( "uvcvideo", false );
    qDebug() << "UVCvideo module added";
}

void
Test::testFindOriginalCam ()
{

}

void
Test::testStream ()
{

}
