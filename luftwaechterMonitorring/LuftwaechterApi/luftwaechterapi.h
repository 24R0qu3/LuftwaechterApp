#ifndef LUFTWAECHTERAPI_H
#define LUFTWAECHTERAPI_H

#include <QObject>
#include <QQmlEngine>
#include <QQmlContext>


class LuftwaechterApi;
using LuftwaechterApi_ptr = LuftwaechterApi*;

class LuftwaechterApi : public QObject
{
    using Super = QObject;

    Q_OBJECT

public:
    explicit LuftwaechterApi( QQmlEngine * engine = nullptr, QJSEngine * jsEngine = nullptr, const char * uri = nullptr );
    ~LuftwaechterApi();

    static void registerQMLTypes( QQmlEngine * engine, const char * uri = nullptr  );
    static void registerQMLTypes( );
    void register_type( const char * uri = nullptr ) ;
    void register_type( const char * uri, QQmlEngine * engine, QJSEngine * scriptEngine );

    static LuftwaechterApi_ptr create( QQmlEngine * engine, QJSEngine * scriptEngine, const char * uri ) {

        auto instance( _helper_singleton );

        if( instance == nullptr ) {

            instance = new LuftwaechterApi( engine, scriptEngine, uri );
            _helper_singleton = instance;

            registerQMLTypes( engine, uri );
        }

        return instance;
    }


    static  QObject * create_object( QQmlEngine * engine, QJSEngine * scriptEngine, const char * uri ) {

        return qobject_cast< QObject * >( create( engine, scriptEngine, uri ));
    }

    static  QObject * create_object( QQmlEngine * engine, QJSEngine * scriptEngine ) {

        return create_object( engine, scriptEngine, nullptr );
    }

    static LuftwaechterApi_ptr instance( ) { return _helper_singleton; }

    void setContextProperty( QQmlEngine * engine, QString const & contextName ) {

        _engine = engine;

        if( _engine ) {

            _engine->rootContext( )->setContextProperty( contextName, this );
        }
    }

private:
    static LuftwaechterApi_ptr _helper_singleton;
    QQmlEngine * _engine;

signals:

};

#endif // LUFTWAECHTERAPI_H
