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


POST 	/api/v1/msg/new/?user_id=102	
Отправить новое сообщение. Сообщение ограниченной длины, любого символьного содержания.
Входной формат: 
	{
		"user_id": 102,
		"msg_content": "tra ta ta"
	}
Коды возврата:
	200 - Оk
	400 - Bad request (отправка большей длины сообщения)


