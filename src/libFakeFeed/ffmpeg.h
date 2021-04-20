#include "QString"
#include "QObject"

class ffmpeg : public QObject {

  Q_OBJECT
//  Q_PROPERTY( READ hello )

  public:
    explicit ffmpeg (QObject* parent = 0) : QObject(parent) {};
    void hello ();
    void stream ( QString textfile, QString device );
};
