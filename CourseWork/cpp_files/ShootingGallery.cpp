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
	while (true)
	{
		cout << "You have commands: MakeNewTarget, DeleteTarget, Shoot, TargetsList, TargetSizeInfo, CoutTarget, End. Enter it: ";
		cin >> command;
		if (command == "MakeNewTarget")
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

		}
		else if (command == "TargetSizeInfo")
		{

		}
		else if (command == "CoutTarget")
		{

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
		cout << "What target-type you want? (RoundTarget, HumanTarget): ";
		string choice;
		cin >> choice;
		if (choice == "RoundTarget")
		{
			int tmp_size;
			do {
				cout << "Enter a RoundTarget size: ";
				cin >> choice;
			} while (ConvertStrToInt(choice, tmp_size) == false);
			cout << endl;
			RoundTarget tmp_target(tmp_size);
			map_RoundTargets[tmp_target.GetIndex()] = tmp_target;
			map_AllTargets[tmp_target.GetIndex()] = &map_RoundTargets[tmp_target.GetIndex()];
			cout << "Succesful! You make a target with index: " + to_string(tmp_target.GetIndex()) << endl;
			break;
		}
		else if (choice == "HumanTarget")
		{
			break;
		}
		else
		{
			cout << "Unkonown target-type: \"" + choice << "\" Try it again please!" << endl;
		}
	}
}

void ShootingGallery::DeleteTarget()
{
	while (true)
	{
		cout << "Enter a command: Delete 'index', Delete All: ";
		string command;
		cin >> command;
		if (command == "Delete")
		{
			cin >> command; 
			if (command == "All")
			{
				map_AllTargets.clear();
				map_HumanTargets.clear();
				map_RoundTargets.clear();
				cout << "Deleting succesful!" << endl;
				break;
			}
			else
			{
				int tmp_index;
				while (ConvertStrToInt(command, tmp_index) == false)
				{
					cout << "Enter a Target index: ";
					cin >> command;
				}
				if (map_AllTargets.count(tmp_index))
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
					break;
				}
				else
				{
					cout << "There is no Target with that: \"" + to_string(tmp_index) + "\"index" << endl;
				}
			}
		}
		else
		{
			cout << "Unknown command " + command + " Try it again please!" << endl;
		}
	}
}

void ShootingGallery::Shoot()
{
	string command;
}

void ShootingGallery::TargetsList()
{
	RoundTarget asd;
	cout << "We have: ";

}

void ShootingGallery::TargetSizeInfo()
{
	string command;

}

void ShootingGallery::CoutTarget()
{
	string command;

}

void ShootingGallery::End()
{
	cout << "The end." << endl;
}
