#ifndef RANDOM_H
#define RANDOM_H

#include <stdlib.h>
#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrl>

namespace steering_behaviors {

class Random : public QObject {

    Q_OBJECT

public:
    Random():m_manager(NULL),m_useRandomOrg(false),m_store(QList<int>()) {

    }

public:

    static int random(int limit) {
        if (steering_behaviors::INSTANCE->m_useRandomOrg) {
            //
        }

        return rand() % limit;
    }

    static void setInternal(void) {
        steering_behaviors::INSTANCE->m_useRandomOrg = false;
    }

    static void setRandomOrg(void) {
        steering_behaviors::INSTANCE->m_useRandomOrg = true;
    }

public slots:

    void update(QNetworkReply * reply) {

    }

private:

    void refreshStore(void) {
        QUrl url("http://www.random.org/integers/?num=10000&min=1&max=500&col=1&base=10&format=plain&rnd=new");
        QNetworkRequest request(url);
        if (m_manager == NULL)
            m_manager = new QNetworkAccessManager();

        connect(m_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(update(QNetworkReply *)));
        m_manager->get(request);

    }

    QNetworkAccessManager * m_manager;
    bool m_useRandomOrg;
    QList<int> m_store;

};

static Random * INSTANCE;

}

#endif // RANDOM_H
