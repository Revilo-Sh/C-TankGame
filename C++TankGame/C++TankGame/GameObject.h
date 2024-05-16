#pragma once
#include <vector>
#include "Vector3.h"
#include "Matrix3.h"


class GameObject
{
protected:
	MathClasses::Vector3 LocalPosition;
	float LocalRotation;
	MathClasses::Vector3 LocalScale;

	virtual void OnUpdate(float deltaTime);
	virtual void OnDraw();

	GameObject* Parent;
	std::vector<GameObject*> Children;

public:
	GameObject();
	void update(float deltaTime);
	void Draw();

	void Setparent(GameObject* parent);
	GameObject* GetParent();

	const GameObject* GetParent() const;
	GameObject* GetChild(size_t childIndex);

	const GameObject* GetChild(size_t childIndex) const;



	// Setting Local //

	//// Position 
	void SetLocalPosition(MathClasses::Vector3 NewPosition);
	void SetLocalPosition(float newx, float newy);

	//// Scale
	void SetlocalScale(MathClasses::Vector3 NewScale);
	void SetLocalScale(float newX, float NewY);
	
	//// Rotaion
	float SetLocalRotation(float newRotation);

	//////////////////////////////////////////////////////
	
	// Get Local //
	MathClasses::Vector3 GetLocalPosition() const;
	MathClasses::Vector3 GetlocalScale() const;

	//////////////////////////////////////////////////////

	// Getting World //
	MathClasses::Vector3 GetWorldPosition() const;
	float GetWorldRotation() const;
	MathClasses::Vector3 Getworldscale() const;

	//// Getting Fowards Vector
	MathClasses::Vector3 GetForwards() const;
	
	//////////////////////////////////////////////////////

	// Getting Matrix //
	MathClasses::Matrix3 GetLocalMatrix() const;
	MathClasses::Matrix3 GetWorldMatrix() const;

	//////////////////////////////////////////////////////
	void Translate(float x, float y);
	void Translate(MathClasses::Vector3 translation);

	void Rotate(float radians);

	void Scale(float x, float y);
	void Scale(MathClasses::Vector3 scalar);




};

