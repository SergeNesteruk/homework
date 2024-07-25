#include <iostream>
#include <pqxx/pqxx>
#include "Windows.h"
#include <string>
#pragma execution_character_set("utf-8")

using namespace std;

class Userdb
{
private:
public:
	void createTables(pqxx::connection& conn)
	{
		pqxx::transaction t(conn);

		static const char* query = "CREATE TABLE IF NOT EXISTS public.user (	\
		id serial NOT NULL,													\
		fname text NOT NULL,												\
		second_name text NOT NULL,											\
		email text NOT NULL,												\
		CONSTRAINT user_pk PRIMARY KEY(id)									\
		); ";

		static const char* query2 = "CREATE TABLE IF NOT EXISTS public.phone_number (	\
		id serial NOT NULL,													\
		user_id int NULL,													\
		phone_number int8 NULL,												\
		CONSTRAINT phone_number_pk PRIMARY KEY(id),							\
		CONSTRAINT phone_number_user_fk FOREIGN KEY(user_id) REFERENCES public.user(id)	\
		);	";

		t.exec(query);
		t.exec(query2);
		t.commit();
	}

	void insertUser(pqxx::connection& conn)
	{
		string newName, newSName, newemail;
		cout << "Введите имя, фамилию и почту:" << endl;
		cin >> newName >> newSName >> newemail;

		pqxx::work tx{ conn };

		tx.exec("INSERT INTO public.user (fname,second_name,email) \
				VALUES ('"+tx.esc(newName) + "', '" + tx.esc(newSName) + "', '" + tx.esc(newemail) + "')");
		
		cout << "Сколько телефонов у пользователя:" << endl;
		int count_phn = 0; long newphn = 0;
		cin >> count_phn;
		
		if (count_phn >=1 )
		{
			cout << "Введите номера телефонов:" << endl;
			for (auto i = 0; i < count_phn; i++)
			{
				cin >> newphn;
				tx.exec("INSERT INTO phone_number (user_id, phone_number) \
					 VALUES (1, '"+ tx.esc( to_string(newphn) )+"')");
			}
		}

		tx.commit();
	}
	void add_phone(pqxx::connection& conn)
	{
		pqxx::work tx{ conn };

		cout << "Введите id пользователя, которому хотите добавить телефон"<<endl;
		int newuid = 0; long newphn = 0;
		cin >> newuid;

		cout << "Введите номер телефона:" << endl;
		cin >> newphn;
		tx.exec("INSERT INTO phone_number (user_id, phone_number) \
				 VALUES ('" + tx.esc(to_string(newuid)) + "', '" + tx.esc(to_string(newphn)) + "')");

		tx.commit();
	}

	void change_data(pqxx::connection& conn)
	{
		pqxx::work tx{ conn };

		cout << "Какие данные надо поменять (name,second_name, email, all):";
		string change_data;
		cin >> change_data;

		if(change_data == "name")
		{
			cout << "Введите id пользователя которого нужно изменить:" << endl;
			int changeuid;
			cin >> changeuid;

			string newName;
			cout << "Введите имя" << endl;
			cin >> newName;

			tx.exec("UPDATE public.user \
				SET fname = '" + tx.esc(newName) + "' \
				WHERE id = '" + tx.esc(to_string(changeuid)) + "'");
		}
		else if (change_data == "second_name")
		{
			cout << "Введите id пользователя которого нужно изменить:" << endl;
			int changeuid;
			cin >> changeuid;

			string newSName;
			cout << "Введите фамилию" << endl;
			cin >> newSName;

			tx.exec("UPDATE public.user \
				SET second_name = '" + tx.esc(newSName) + "' \
				WHERE id = '" + tx.esc(to_string(changeuid)) + "'");
		}
		else if (change_data == "email")
		{
			cout << "Введите id пользователя которого нужно изменить:" << endl;
			int changeuid;
			cin >> changeuid;

			string newemail;
			cout << "Введите email" << endl;
			cin >> newemail;

			tx.exec("UPDATE public.user \
				SET email = '" + tx.esc(newemail) + "' \
				WHERE id = '" + tx.esc(to_string(changeuid)) + "'");
		}
		else if (change_data == "all")
		{
			cout << "Введите id пользователя которого нужно изменить:" << endl;
			int changeuid;
			cin >> changeuid;

			string newName, newSName, newemail;
			cout << "Введите имя, фамилию и почту:" << endl;
			cin >> newName >> newSName >> newemail;

			tx.exec("UPDATE public.user \
				SET fname = '" + tx.esc(newName) + "', second_name = '" + tx.esc(newSName) + "', email = '" + tx.esc(newemail) + "' \
				WHERE id = '" + tx.esc(to_string(changeuid)) + "'");
		}

		tx.commit();
	}

	void delete_phone(pqxx::connection& conn)
	{
		pqxx::work tx{ conn };
		cout << "Введите id телефонного номера, который нужно удалить:" << endl;
		int delphid;
		cin >> delphid;

		tx.exec("DELETE FROM public.phone_number \
				  WHERE id = '" + tx.esc(to_string(delphid)) + "'");

		tx.commit();
	}

	void delete_user(pqxx::connection& conn)
	{
		pqxx::work tx{ conn };
		cout << "Введите id пользователя, которого нужно удалить:" << endl;
		int deluid;
		cin >> deluid;

		tx.exec("DELETE FROM public.phone_number \
			WHERE user_id = '" + tx.esc(to_string(deluid)) + "'");

		tx.exec("DELETE FROM public.user \
				  WHERE id = '" + tx.esc(to_string(deluid)) + "'");
		tx.commit();
	}

	void search(pqxx::connection& conn)
	{
		pqxx::work tx{ conn };

		cout << "Как найти клиента (name, second_name, email,phone_number):";
		string search;
		cin >> search;

		for (auto [name, sname, email, phone] : tx.query<string, string, string, long>(
			"SELECT fname, second_name, email, p.phone_number FROM user u \
			LEFT JOIN phone_number p ON u.id = p.user_id \
			WHERE fname = '"+tx.esc(search)+"' OR second_name = '"+ tx.esc(search)+"' OR email = '" + tx.esc(search) + "' OR p.phone_number = '" + tx.esc(search) + "'"))
		{
			cout << name << " " << sname << " " << email << " " << phone<<endl;
		}
	}
};



int main()
{
	//setlocale(LC_ALL, "");
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	setvbuf(stdout, nullptr, _IOFBF, 1000);
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	try
	{
		pqxx::connection c(
			"host=localhost "
			"port=5432 "
			"dbname=task01 "
			"user=task01user "
			"password=task01user "
		);
		Userdb U;

		U.createTables(c);

		U.insertUser(c);

		U.add_phone(c);

		U.change_data(c);

		U.delete_phone(c);

		U.delete_user(c);

		U.search(c);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception happend: " << e.what() << std::endl;
	}

};