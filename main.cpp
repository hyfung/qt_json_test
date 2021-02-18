#include <QCoreApplication>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QJsonObject jsonObj;
    QJsonObject jsonObj2;
    jsonObj2["baz"] = 123;

    jsonObj["foo"] = "bar";
    jsonObj["json"] = jsonObj2;

    QJsonDocument doc(jsonObj);

    QString strJson(doc.toJson(QJsonDocument::Compact));

    std::string jsonString = strJson.toStdString();

    QJsonArray jsonArray = QJsonDocument::fromJson(strJson.toUtf8()).array();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(strJson.toUtf8());

    QJsonObject decodedObject = jsonDoc.object();

    cout << decodedObject["foo"].toString().toStdString() << endl;
    cout << decodedObject["json"].toObject()["baz"].toInt() << endl;

    cout << "Helloworld" << endl;

    cout << strJson.toStdString() << endl;


    return 0;
}
