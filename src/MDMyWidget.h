#include <qgroupbox.h>
#include <qcheckbox.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <dzcolorwgt.h>
#include <qvariant.h>

//class MDMyWidget {
class MDMyWidget : public QGroupBox {
	Q_OBJECT

public:
	
	/// Constructor ////
	MDMyWidget(QString title = "", QWidget* parent = 0);

	/// Destructor ///
	virtual ~MDMyWidget();

	QCheckBox *wCheckbox;
	QPushButton *wPixmap;
	QPushButton *wLabel;
	QPushButton *wEdit;
	QPushButton *wSetPixmap;
	QPushButton *wDelete;
	QLabel *owType;
	QPushButton *wNotes;
	QPushButton *wInfos;


public slots:
	// some public functions
	int minimumWidth() const;
	int minimumHeight() const;


private:
	int totalHeight;
	int totalWidth;
	// some private variables


private slots:

	// some private functions

};