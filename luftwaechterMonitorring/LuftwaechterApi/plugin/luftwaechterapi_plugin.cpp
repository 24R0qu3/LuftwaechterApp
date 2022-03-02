#include "luftwaechterapi_plugin.h"
#include "luftwaechterapi.h"

#include <qqml.h>

void LuftwaechterApiPlugin::initializeEngine(QQmlEngine *engine, const char *uri)
{
    if( engine != nullptr )
    {

        auto context( engine->rootContext( ));

        if( context ) {

            LuftwaechterApi::create_object( engine, nullptr );

            Q_UNUSED( uri )
        }
    }
}

void LuftwaechterApiPlugin::registerTypes(const char *uri)
{
    Q_UNUSED( uri );
    LuftwaechterApi::registerQMLTypes();
}


