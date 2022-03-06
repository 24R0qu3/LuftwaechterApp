#include "sensorrequester.hpp"

SensorRequester::SensorRequester(QObject *parent)
    : QObject{parent}
{

}

SensorRequester::~SensorRequester()
{

}

void SensorRequester::vRequest()
{
    startRequest( QUrl( m_baseUrl ) );
}

void SensorRequester::startRequest(const QUrl &requestedUrl)
{
    url = requestedUrl;
    httpRequestAborted = false;

    //! [qnam-download]
    reply.reset(qnam.get(QNetworkRequest(url)));
    //! [qnam-download]
    //! [connecting-reply-to-slots]
    connect(reply.get(), &QNetworkReply::finished, this, &SensorRequester::httpFinished);
    //! [networkreply-readyread-1]
    connect(reply.get(), &QIODevice::readyRead, this, &SensorRequester::httpReadyRead);
    //! [networkreply-readyread-1]
#if QT_CONFIG(ssl)
    //! [sslerrors-1]
    connect(reply.get(), &QNetworkReply::sslErrors, this, &SensorRequester::sslErrors);
    //! [sslerrors-1]
#endif
    //! [connecting-reply-to-slots]

}

void SensorRequester::vSetUpRepeatedRequest()
{
    QTimer::singleShot( m_requestInterval, this, &SensorRequester::requestAgain );
}

void SensorRequester::vEvaluateReceivedData(QString receivedData_)
{
    auto data = receivedData_.split(" ");

    setSensorValue( data[ 0 ] );
    setSensorUnit( data[ 1 ] );
}

void SensorRequester::httpFinished()
{
    //! [networkreply-error-handling-1]
    QNetworkReply::NetworkError error = reply->error();
    const QString &errorString = reply->errorString();
    //! [networkreply-error-handling-1]
    reply.reset();
    //! [networkreply-error-handling-2]
    if (error != QNetworkReply::NoError) {

        // For "request aborted" we handle the label and button in cancelDownload()

        return;
    }
    //! [networkreply-error-handling-2]
}

//! [networkreply-readyread-2]
void SensorRequester::httpReadyRead()
{
    // This slot gets called every time the QNetworkReply has new data.
    // We read all of its new data and write it into the file.
    // That way we use less RAM than when reading it at the finished()
    // signal of the QNetworkReply
    if( m_enableRepeatedRequest )
    {
        vSetUpRepeatedRequest();
    }

    vEvaluateReceivedData( reply->readAll() );
}

void SensorRequester::slotAuthenticationRequired(QNetworkReply *, QAuthenticator *authenticator)
{
    qInfo() << "slotAuthenticationRequired";
}

#if QT_CONFIG(ssl)
//! [sslerrors-2]
void SensorRequester::sslErrors(const QList<QSslError> &errors)
{
    QString errorString;
    for (const QSslError &error : errors) {
        if (!errorString.isEmpty())
            errorString += '\n';
        errorString += error.errorString();
    }
}
//! [sslerrors-2]
#endif

const QString &SensorRequester::baseUrl() const
{
    return m_baseUrl;
}

void SensorRequester::setBaseUrl(const QString &newBaseUrl)
{
    if (m_baseUrl == newBaseUrl)
        return;
    m_baseUrl = newBaseUrl;
    emit baseUrlChanged();
}

bool SensorRequester::enableRepeatedRequest() const
{
    return m_enableRepeatedRequest;
}

void SensorRequester::setEnableRepeatedRequest(bool newEnableRepeatedRequest)
{
    if (m_enableRepeatedRequest == newEnableRepeatedRequest)
        return;
    m_enableRepeatedRequest = newEnableRepeatedRequest;
    emit enableRepeatedRequestChanged();
}

int SensorRequester::requestInterval() const
{
    return m_requestInterval;
}

void SensorRequester::requestAgain()
{
    vRequest();
}

void SensorRequester::setRequestInterval(int newRequestInterval)
{
    if (m_requestInterval == newRequestInterval)
        return;
    m_requestInterval = newRequestInterval;
    emit requestIntervalChanged();
}

const QString &SensorRequester::sensorValue() const
{
    return m_sensorValue;
}

void SensorRequester::setSensorValue(const QString &newSensorValue)
{
    if (m_sensorValue == newSensorValue)
        return;
    m_sensorValue = newSensorValue;
    emit sensorValueChanged();
}

const QString &SensorRequester::sensorUnit() const
{
    return m_sensorUnit;
}

void SensorRequester::setSensorUnit(const QString &newSensorUnit)
{
    if (m_sensorUnit == newSensorUnit)
        return;
    m_sensorUnit = newSensorUnit;
    emit sensorUnitChanged();
}
