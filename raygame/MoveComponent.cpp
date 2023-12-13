#include "MoveComponent.h"
#include "Transform2D.h"
#include "Actor.h"

MoveComponent::MoveComponent(float maxSpeed, Actor* owner) : Component(owner, "MoveComponent")
{
	m_maxSpeed = maxSpeed;
}

void MoveComponent::update(float deltaTime)
{
	//Store what the current position is.
	MathLibrary::Vector2 position = getOwner()->getTransform()->getLocalPosition();

	//If thevelocity is greater than the max speed.
	if (getVelocity().getMagnitude() > getMaxSpeed())
	{
		//...normalize and scale it by the max speed to clamp it.
		MathLibrary::Vector2 newVelocity = getVelocity().getNormalized() * getMaxSpeed();
		setVelocity(newVelocity);
	}

	//Increase the current position by the velocity to get the new position
	position = position + getVelocity() * deltaTime;
	//Set the transforms position to be the new position
	getOwner()->getTransform()->setLocalPosition(position);
}
