#include "uiwidget.h"
#include "uiwidgetplugin.h"

#include <QtPlugin>

UIWidgetPlugin::UIWidgetPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void UIWidgetPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool UIWidgetPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *UIWidgetPlugin::createWidget(QWidget *parent)
{
    return new UIWidget(parent);
}

QString UIWidgetPlugin::name() const
{
    return QLatin1String("UIWidget");
}

QString UIWidgetPlugin::group() const
{
    return QLatin1String("");
}

QIcon UIWidgetPlugin::icon() const
{
    return QIcon();
}

QString UIWidgetPlugin::toolTip() const
{
    return QLatin1String("");
}

QString UIWidgetPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool UIWidgetPlugin::isContainer() const
{
    return false;
}

QString UIWidgetPlugin::domXml() const
{
    return QLatin1String("<widget class=\"UIWidget\" name=\"uIWidget\">\n</widget>\n");
}

QString UIWidgetPlugin::includeFile() const
{
    return QLatin1String("uiwidget.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(uiwidgetplugin, UIWidgetPlugin)
#endif // QT_VERSION < 0x050000
