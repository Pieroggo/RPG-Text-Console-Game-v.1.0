#pragma once
#include<string>
using namespace std;
class storyboard {
public:
	string story[100]{ "You wake up in a sewer, feeling dizzy and very weak. You stand up to a good look at your surroundings. ", //0
		"You see a rat in the distance. The moment it spots you, it jumps near you and tries to bite you. You decide to show the rat who is the boss.",//1
		"After defeating the rat, you turn around and see a pack of weak rats scurrying around. They seem to not notice you....yet.",//2
		"You have decided to pick on this infestation of rats and try to get rid of it. You firstly take on the 3 rats in front of you.",//3
		"You kill the rats. You feel like a horrible person by picking on weak animals. Well, you're not going to take on weak creatures anymore ;)",
		"The waters grumble around you. Suddenly, a piece of sludge, you thought was normal, comes to life. You decided to make it dead again.",
		"After destroying the slime, you hear a loud scream in the distance. You fear.",
		"A mud monster comes from the darkness and shouts: 'You killed my baby boi, I will smash you!' You decide to smash IT instead.",
		"As you decimate the last piece of the Mud Monster, the water around you gets muddy and more sticky. But, you finally see the manhole to the outer world.",
		"Now the only thing that stands in your way to freedom is this manhole. DESTROY IT!",
		"You finally get out of the sewers, only to find yourself in the middle of and unknown forest.",
		"As you wander around, an Orc appears. It attacks you with vicious anger, so you try to defend yourself from it.",
		"As you strike the Orc one final time, its body collapses into dust, which then flies in the air. While watching the dust fly away, another monster lurks.",
		"The goblin you knew about jumps. Wow, very original.",
		"You kill the goblin, its body disintegrates, blah blah blah. Because of your boredom, you accidentally bump into a tree. Which comes to life and tries to murder you.",
		"Yup, you are fighting trees now. Kinda feels like Minecraft.",
		"You use Dead Ent as firewood to get warmer.",
		"You hear an angry voice behind you. 'You monster! You killed our guardian! Now feel my wrath!'",
		"After a fierce battle (;P), the fairy stops and both of you apologise. She decides to take you to her master, The Elf Lord.",
		"The Elf Lord is possessed by an evil force and you have to bring him back to his senses. (Totally not defeat him or anything)",
		"After dealing with the Elf Lord, you see a long trail of dust coming in one direction. You see a dark castle in the distance. You decide to approach it.",
		"Entering this castle was a bad idea. You suddenly shrink. And you have to fight this sponge.",
		"The sponge is defeated. OR IS IT?",
		"No, it is not, it just evolved.",
		"OK, this time it is for good. You continue going deeper into the castle.",
		"....................................... Yes..............A fork.",
		"This feels like a weird fever dream, still, you have to get to the bottom of this nonsense. You go on.",
		"You encounter a bed. Too bad it is too big for you. And that the blanket is attacking you.",
		"After defeating the blanket, you use a piece of it to warm yourself up a bit. After a moment of resting, you decide to explore the rest of the castle.",
		"While entering the kitchen, it seems you were attacked by a spoon. A dangerous looking one, as well."
	};//potem siê zwiêkszy
	void printStory(int a) {
		cout << story[a]<<endl;
	}
};
