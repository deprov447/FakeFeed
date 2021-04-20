#include "QString"
#include "QObject"

class FFMPEG : public QObject {

  Q_OBJECT
//  Q_PROPERTY( READ hello )

  public:
    explicit FFMPEG (QObject* parent = 0) : QObject(parent) {};
    void hello ();
    void stream ( QString textfile, QString device );
};
