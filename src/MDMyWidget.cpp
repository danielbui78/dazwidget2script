#include <qwidget.h>
#include <qgroupbox.h>

#include <qcheckbox.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qgridlayout.h>

#include "MDMyWidget.h"

MDMyWidget::MDMyWidget(QString title, QWidget* parent) :
	QGroupBox(title, parent)
{
	setFixedSize( 500, 200 );

	//all widgets are set as public items in the header file
	wCheckbox = new QCheckBox("checkbox", this);
	wPixmap = new QPushButton("pixmap", this);
	wLabel = new QPushButton("label", this);
	wEdit = new QPushButton("edit", this);
	wSetPixmap = new QPushButton("setpixmap", this);
	wDelete = new QPushButton("delete", this);
	owType = new QLabel("type:", this);
	wNotes = new QPushButton("notes", this);
	wInfos = new QPushButton("infos", this);


	//get the layout
	//QLayout *oLayout = this->layout();

	QGridLayout* oLayout = new QGridLayout(this);

	oLayout->addWidget(wCheckbox, 1, 0);
	oLayout->addWidget(wPixmap, 0, 1, 3, 1);
	oLayout->addWidget(wLabel, 1, 3);
	oLayout->addWidget(wEdit, 1, 4);
	oLayout->addWidget(wSetPixmap, 1, 5);
	oLayout->addWidget(wDelete, 1, 6);
	oLayout->addWidget(owType, 0, 5);
	oLayout->addWidget(wNotes, 1, 7);
	oLayout->addWidget(wInfos, 1, 8);

	//initialize
	//some widgets initialization


	//this->setLayout(oLayout);
	setLayout(oLayout);

}

MDMyWidget::~MDMyWidget()
{

}

int MDMyWidget::minimumWidth() const
{
	return 500;
}

int MDMyWidget::minimumHeight() const
{
	return 500;
}

#include "moc_MDMyWidget.cpp"

