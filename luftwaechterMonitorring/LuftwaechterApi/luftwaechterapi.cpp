#include "luftwaechterapi.h"
#include "mytest.h"

LuftwaechterApi_ptr LuftwaechterApi::_helper_singleton( nullptr );

QQmlEngine * enginePtrSingleton { nullptr };


LuftwaechterApi::LuftwaechterApi(QQmlEngine *engine, QJSEngine *jsEngine, const char *uri)
{
    Q_UNUSED(engine);
    Q_UNUSED(jsEngine);
    Q_UNUSED(uri);
}

LuftwaechterApi::~LuftwaechterApi()
{
    _helper_singleton = nullptr;
}

void LuftwaechterApi::registerQMLTypes(QQmlEngine *engine, const char *uri)
{
    enginePtrSingleton = engine;
    Q_UNUSED( uri );

//    engine->addImportPath("qrc:/qml/MyImportPath" );
}

void LuftwaechterApi::registerQMLTypes()
{
    qmlRegisterType<LuftwaechterApi>("LuftwaechterApi", 1, 0, "PluginExample");
    qmlRegisterType<MyTest>("LuftwaechterApi", 1,0, "MyTest");
}
