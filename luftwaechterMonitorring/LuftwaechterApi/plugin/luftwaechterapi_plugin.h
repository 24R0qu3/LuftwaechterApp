#ifndef PLUGINEXAMPLE_PLUGIN_H
#define PLUGINEXAMPLE_PLUGIN_H

#include <QQmlExtensionPlugin>

class LuftwaechterApiPlugin : public QQmlExtensionPlugin
{
    using Super = QQmlExtensionPlugin;

    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void initializeEngine( QQmlEngine * engine, char const * uri ) final override;
    void registerTypes(const char *uri) final override;
};

#endif // PLUGINEXAMPLE_PLUGIN_H
