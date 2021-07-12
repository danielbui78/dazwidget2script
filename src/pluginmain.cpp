#include "dzplugin.h"
#include "dzapp.h"

#include <qstring.h>

#include "version.h"
#include "MDMyWidget.h"

DZ_PLUGIN_DEFINITION("DazWidget2Script");

DZ_PLUGIN_AUTHOR("plugin author");

DZ_PLUGIN_VERSION(PLUGIN_MAJOR, PLUGIN_MINOR, PLUGIN_REV, PLUGIN_BUILD);

DZ_PLUGIN_DESCRIPTION(QString(
	"DazPluginBase Documentation")
);

// TODO: 1. Rename the namespace to avoid conflict with other plugins
//       2. Generate new GUID and replace the one here
//DZ_PLUGIN_CLASS_GUID(MDMyWidget, 0e027c5b-b6b1-43af-9b9e-177f62f72ca2);
DZ_PLUGIN_CUSTOM_CLASS_GUID(MDMyWidget, 0e027c5b-b6b1-43af-9b9e-177f62f72ca2);

QObject* MDMyWidgetFactory::createInstance(const QVariantList& args) const
{
	QWidget* parent = NULL;
	QString title = "";
	int num_args = args.count();
	for (int i = 0; i < num_args; i++)
	{
		QVariant qvar = args[i];
		const char *typeName = qvar.typeName();
		QString typeString(typeName);
		if (typeString.toLower().contains("qobject*"))
		{
			QObject *obj = qvar.value<QObject*>();
			const char* className = obj->metaObject()->className();
			if (obj->inherits("QWidget"))
			{
				parent = (QWidget*) obj;
			}
		}
		else if (typeString.toLower().contains("qstring"))
		{
			title = qvar.value<QString>();
		}

	}
	return (QObject*) new MDMyWidget(title, parent);
}

QObject* MDMyWidgetFactory::createInstance() const
{
	return (QObject*) new MDMyWidget();
}
