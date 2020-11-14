import json

class _User:
	comp: int
	uid: int

IN_FILE = 'in.json';
OUT_FILE = 'out.json';

def add_new_user(users, uid):
	user = _User()
	user.comp = 1
	user.uid = uid
	return users + [user]

def add_completed_task(users, uid) :
	for i in range(len(users)):
		if users[i].uid == uid:
			users[i].comp += 1
			return users;
	return add_new_user(users, uid);

def parse_users_json_file(users, fileName):
	with open(fileName) as file:
		data = json.load(file)
	for json_item in data:
		uid = json_item['userId']
		ucomp = json_item['completed']
		if ucomp:
			users = add_completed_task(users, uid)
	return users

def create_report_json_file(users, fileName):
	data = []
	for user in users:
		json_item = {"task_completed":user.comp, "userId":user.uid};
		data += [json_item]
	with open(OUT_FILE, "w") as file:
		json.dump(data, file, indent=2)

users = []
users = parse_users_json_file(users, IN_FILE)
create_report_json_file(users, OUT_FILE);