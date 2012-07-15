#include "model/random.h"
#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrl>

class RandomSource : public QObject {

    Q_OBJECT

private:

    QNetworkAccessManager * m_manager;
    bool m_useRandomOrg;
    QList<int> m_store;

public:

    RandomSource():
        m_manager(new QNetworkAccessManager()),
        m_useRandomOrg(false),
        m_store(QList<int>()) {}

    ~RandomSource() {
        if (m_manager != NULL)
            delete m_manager;
    }

public slots:

    inline void update(QNetworkReply * reply) {

    }

    inline void setInternal(void) {
        m_useRandomOrg = false;
    }

    inline void setRandomOrg(void) {
        m_useRandomOrg = true;
    }

private:

    inline void refreshStore(void) {
        QUrl url("http://www.random.org/integers/?num=10000&min=1&max=500&col=1&base=10&format=plain&rnd=new");
        QNetworkRequest request(url);
        if (m_manager == NULL)
            m_manager = new QNetworkAccessManager();

        connect(m_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(update(QNetworkReply *)));
        m_manager->get(request);

    }

};

//RandomSource SOURCE;

int steering_behaviors::Random::random(int limit) {
    //RandomSource src;
    /*if (INSTANCE->m_useRandomOrg) {
        //
    }*/

    return rand() % limit;
}

void steering_behaviors::Random::setInternal(void) {
    //SOURCE::setInternal();
}

void steering_behaviors::Random::setRandomOrg(void) {
    //SOURCE::setRandomOrg();
}
