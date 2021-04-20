#include "QString"

class Module {
  public :
    bool findOriginalCam ();
    bool manageDevice ( QString deviceName, bool toRemove );
  private :
    QString m_OriginalCam;
}
