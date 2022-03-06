#ifndef SENSORREQUESTER_HPP
#define SENSORREQUESTER_HPP

#include <QObject>
#include <QtNetwork>
#include <QTimer>

class SensorRequester : public QObject
{
    Q_OBJECT
public:
    explicit SensorRequester(QObject *parent = nullptr);
    ~SensorRequester();

    Q_PROPERTY( QString baseUrl READ baseUrl WRITE setBaseUrl NOTIFY baseUrlChanged )
    Q_PROPERTY( bool enableRepeatedRequest READ enableRepeatedRequest  WRITE setEnableRepeatedRequest  NOTIFY enableRepeatedRequestChanged)
    Q_PROPERTY(int requestInterval READ requestInterval  WRITE setRequestInterval  NOTIFY requestIntervalChanged)

    Q_PROPERTY( QString sensorValue READ sensorValue  WRITE setSensorValue  NOTIFY sensorValueChanged )
    Q_PROPERTY( QString sensorUnit READ sensorUnit  WRITE setSensorUnit  NOTIFY sensorUnitChanged )

    Q_INVOKABLE void vRequest( );

    void startRequest( const QUrl &requestedUrl );
    void vSetUpRepeatedRequest();
    void vEvaluateReceivedData( QString receivedData_ );

    const QString &baseUrl() const;
    void setBaseUrl(const QString &newBaseUrl);

    bool enableRepeatedRequest() const;
    void setEnableRepeatedRequest(bool newEnableRepeatedRequest);

    int requestInterval() const;
    void setRequestInterval(int newRequestInterval);

    const QString &sensorValue() const;
    void setSensorValue(const QString &newSensorValue);

    const QString &sensorUnit() const;
    void setSensorUnit(const QString &newSensorUnit);

signals:

    void baseUrlChanged();

    void enableRepeatedRequestChanged();

    void requestIntervalChanged();

    void sensorValueChanged();

    void sensorUnitChanged();

private:
    QTimer * repeatedRequestTimer = new QTimer();

    QUrl url;
    QScopedPointer<QNetworkReply, QScopedPointerDeleteLater> reply;
    QNetworkAccessManager qnam;
    bool httpRequestAborted = false;

    QString m_baseUrl;

    bool m_enableRepeatedRequest = true;

    int m_requestInterval = 1000;

    QString m_sensorValue;

    QString m_sensorUnit;

private slots:
    void requestAgain();

    void httpFinished();
    void httpReadyRead();
    void slotAuthenticationRequired(QNetworkReply *, QAuthenticator *authenticator);
#if QT_CONFIG(ssl)
    void sslErrors(const QList<QSslError> &errors);
#endif
};

#endif // SENSORREQUESTER_H
