#include "../h_files/ShootingGallery.h"

void ShootingGallery::Start()
{
	cout << "Welcome to My ShootingGallery simulator!" << endl;
	string command;
	do {
		cout << "Enter your's shooter name please: ";
		getline(cin, command);
	} while (command == "");
	currShooter.SetName(command);
	cout << "Your name is: " << currShooter.GetName() << endl;
	cout << "ls - CommandList, back - back to previus page." << endl;
	while (true)
	{
		cout << currShooter.GetName() << "/~: ";
		cin >> command;
		if (command == "ls")
		{
			cout << "You have commands: MakeNewTarget, DeleteTarget, Shoot, TargetsList, TargetInfo, End." << endl;
		}
		else if (command == "MakeNewTarget")
		{
			this->MakeNewTarget();
		}
		else if (command == "DeleteTarget")
		{
			this->DeleteTarget();
		}
		else if (command == "Shoot")
		{

		}
		else if (command == "TargetsList")
		{
			this->TargetsList();
		}
		else if (command == "TargetInfo")
		{
			this->TargetInfo();
		}
		else if (command == "End")
		{
			break;
		}
		else
		{
			cout << "Unkonown command: \"" + command << "\" Try it again please!" << endl;
		}
	}
	this->End();
}

void ShootingGallery::MakeNewTarget()
{
	while (true)
	{
		cout << currShooter.GetName() << "/~" <<  "/MakeNewTarget: ";
		string command;
		cin >> command;
		if (command == "RoundTarget")
		{
			int tmp_size;
			do {
				cin >> command;
			} while (ConvertStrToInt(command, tmp_size) == false);
			cout << endl;
			int tmp_index = GetNextIndex();
			map_RoundTargets[tmp_index] = RoundTarget(tmp_size);
			map_AllTargets[tmp_index] = &map_RoundTargets[tmp_index];
			cout << "Succesful! You make a target with index: " << tmp_index << endl;
		}
		else if (command == "ls")
		{
			cout << "What target-type you want? (RoundTarget 'size', HumanTarget 'size'): ";
		}
		else if (command == "HumanTarget")
		{
			break;
		}
		else if (command == "back")
		{
			break;
		}
		else
		{
			cout << "Unkonown target-type: \"" + command << "\" Try it again please!" << endl;
		}
	}
}

void ShootingGallery::DeleteTarget()
{
	while (true)
	{
		cout << currShooter.GetName() << "/~/DeleteTarget: ";
		string command;
		cin >> command;
		if (command == "DeleteAll")
		{
			map_AllTargets.clear();
			map_HumanTargets.clear();
			map_RoundTargets.clear();
			cout << "Deleting succesful!" << endl;
		}
		else if (command == "ls")
		{
			cout << "Enter a command: Delete 'index', DeleteAll.";
		}
		else if (command == "Delete")
		{
			int tmp_index;
			if (TakeIndex(tmp_index))
			{
				string tmp_type = map_AllTargets[tmp_index]->GetType();
				map_AllTargets.erase(tmp_index);
				if (tmp_type == "RoundTarget")
				{
					map_RoundTargets.erase(tmp_index);
				}
				else if (tmp_type == "HumanTarget")
				{
					map_HumanTargets.erase(tmp_index);
				}
				cout << "Deleting succesful!" << endl;
			}
			else
			{
				cout << "There is no Target with that: \"" + to_string(tmp_index) + "\"index" << endl;
			}
		}
		else if (command == "back")
		{
			break;
		}
		else
		{
			cout << "Unknown command \"" + command + "\" Try it again please!" << endl;
		}
	}
}

void ShootingGallery::Shoot()
{
	string command;
}

void ShootingGallery::TargetsList()
{
	cout << "We have \"" << map_AllTargets.size() << "\" allType targets" << endl;
	for (const auto& it : map_AllTargets)
	{
		cout << "index[" << it.first << "], type: " << it.second->GetType() << ", size: " << it.second->GetSize() << endl;
	}
	cout << "Thats all!" << endl;
}

void ShootingGallery::TargetInfo()
{
	while (true)
	{
		cout << currShooter.GetName() << "/~/TargetInfo: ";
		string command;
		cin >> command;
		if (command == "Info" || command == "CoutTarget")
		{
			int tmp_index;
			bool index = TakeIndex(tmp_index);
			if (command == "Info")
			{
				cout << "index[" << tmp_index << "], type: " << map_AllTargets.at(tmp_index)->GetType() << ", size: " << map_AllTargets.at(tmp_index)->GetSize() << endl;
			}
			else if (command == "ls")
			{
				cout << "You have command: Info 'index', CoutTarget 'index': ";
			}
			else if (command == "CoutTarget")
			{
				map_AllTargets.at(tmp_index)->CoutTarget();
				cout << endl;
			}
			else
			{
				cout << "There is not Target with \"" << tmp_index << "\" index. Try again!" << endl;
			}
		}
		else if (command == "back")
		{
			break;
		}
		else 
		{
			cout << "Unknown command \"" + command + "\" Try it again please!" << endl;
		}
	}
}

void ShootingGallery::End()
{
	cout << "The end." << endl;
}

bool ShootingGallery::TakeIndex(int& tmp_index)
{
	tmp_index = 0;
	string command;
	cout << "Enter an Target index: ";
	do
	{
		cin >> command;
	} while (ConvertStrToInt(command, tmp_index) == false);
	return map_AllTargets.count(tmp_index);
}
