/*!
 * \file
 * \brief Заголовочный файл, определяющий функции сервера для взаимодействия с клиентом
 */

#ifndef FUNCTIONSFORSERVER_H
#define FUNCTIONSFORSERVER_H

#include <QStringList>
#include <QString>


/*!
 * \brief parsing - функция, выполняющая парсинг сообщений со стороны клиента. Данная функция выделяет команды, параметры и аргументы из строки клиента и вызывает соответствующие функции, передавая в них параметры, полученные от клиента.
 * \param [in] command - строка, содержащая сообщение, отправленное клиентом
 * \param [in] socketDescriptor - дескриптор сокета клиента, от которого было получено сообщение
 * \return Возвращает результат работы функции, вызываемой клиентом
 * \todo Обработка исключений Qt, не поддерживаемая использованием try/catch
 * \todo Замена дерева if/else более эффективным методом проверки комманд
 */
QByteArray parsing(QString data_from_client, qintptr socketDescriptor);

/*!
 * \brief auth - функция, выполняющая [проверку существования аккаунта] и аутентификацию пользователя
 * \param [in] login - логин, полученный из строки сообщения пользователя
 * \param [in] password - пароль, полученный из строки сообщения пользователя
 * \param [in] socketDescriptor - дескриптор сокета клиента, совершающего аутентификацию
 * \return Возвращает сообщение с результатом аутентификации пользователя
 */
QByteArray auth(QString login, QString password, qintptr socketDescriptor);

/*!
 * \brief reg - функция, выполняющая [проверку существования аккаунта] и регистрацию пользователя
 * \param [in] login - создаваемый логин, полученный из строки сообщения пользователя
 * \param [in] password - создаваемый пароль, полученный из строки сообщения пользователя
 * \param [in] email - электронная почта, полученная из строки сообщения пользователя
 * \param [in] socketDescriptor - дескриптор сокета клиента, совершающего регистрацию
 * \return Возвращает сообщение с результатом регистрации пользователя
 */
QByteArray reg(QString login, QString password, QString email, qintptr socketDescriptor);

QByteArray ReadStatistics(QString login, qintptr socketDescriptor);

QByteArray TestAnswer(QString login, QString numberQuestion, QString condition, QString answer1, QString answer2, QString answer3, QString answer4, qintptr socketDescriptor);

QByteArray conditions(QString numbers, qintptr socketDescriptor);

#endif // FUNCTIONSFORSERVER_H
