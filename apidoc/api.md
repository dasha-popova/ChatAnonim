GET 	/api/v1/msg/?user_id=102
Получить последние сообщения.
Коды возврата:
	200 - Оk
	400 - Bad request
Выходной формат:
	{ 
	  "msgs" : [
			{ 
			  "user_id": 105,
			  "msg_content" : "bla bla bla" 
			},
			{ 
			  "user_id": 108,
			  "msg_content" : "HELLO =)"
			} 
		   ]
	}


POST 	/api/v1/msg/new/	
Отправить новое сообщение.
Входной формат: 
	{
		"user_id": 102,
		"msg_content": "tra ta ta"
	}
Коды возврата:
	200 - Оk
	400 - Bad request 


POST 	/api/v1/users/new/?nick=blabla
Добавление нового пользователя в какую-то комнату.  
Выходной формат: 
	{
		"user_id": 309
	}
Коды возврата:
	200 - Оk
	400 - Bad request 
