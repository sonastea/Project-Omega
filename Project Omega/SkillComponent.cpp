#include "stdafx.h"
#include "SkillComponent.h"

SkillComponent::SkillComponent()
{
	this->skills.push_back(Skill(CONSTITUTION));
	this->skills.push_back(Skill(MELEE_COMBAT));
	this->skills.push_back(Skill(RANGED_COMBAT));
	this->skills.push_back(Skill(ENDURANCE));
}

SkillComponent::~SkillComponent()
{
}

const int SkillComponent::getSkill(const int skill) const
{
	if (skill < 0 || skill >= this->skills.size())
		throw ("ERROR::SKILLCOMPONENT::SKILL DONT NOT EXIST: " + skill);
	else
		return this->skills[skill].getLevel();

}

const void SkillComponent::gainExp(const int skill, const int exp)
{
	if (this->skills.empty() || skill < 0 || skill >= this->skills.size())
		throw ("ERROR::SKILLCOMPONENT::GAINEXP::SKILL DONT NOT EXIST: " + skill);
	else
	{
		this->skills[skill].gainExp(exp);
	}
}
