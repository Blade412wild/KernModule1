#include "PhysicsObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>

//PhysicsObject::PhysicsObject() {
//	
//}

float PhysicsObject::CalculatingDisplacement(float _mass, int _identifier) {

	if (_identifier == 1) {
		Fmotor = PhysicsObject::CalculateFmotorPlayer();
	}
	else {
		Fmotor = PhysicsObject::CalculateFmotorEnemy();
	}

	NormalForce = PhysicsObject::CalculateNormalForce(_mass);
	FrictionCoeffient = PhysicsObject::CalculateFrictionCoeffient(Fmotor, NormalForce);
	Friction = PhysicsObject::CalculateFriction(FrictionCoeffient, NormalForce);
	Fnetto = PhysicsObject::CalculateNettoForce(Fmotor, Friction);
	Acceleration = PhysicsObject::CalculateAcceleration(Fnetto, _mass);
	Velocity = CalculateVelocity(Acceleration);

	float _displacement = Velocity * DeltaTime;
	return _displacement;
}

float PhysicsObject::CalculateVelocity(float _Acceleration) {
	float _velocity;
	_velocity = _Acceleration * DeltaTime;

	return _velocity;
}

float PhysicsObject::CalculateAcceleration(float _NettoForce, float _mass) {
	float _acceleration;
	_acceleration = _NettoForce / _mass;
	return _acceleration;
}

float PhysicsObject::CalculateNettoForce(float _fMotor, float _friction) {
	float _fNetto;
	_fNetto = _fMotor - _friction;
	return _fNetto;
}

float PhysicsObject::CalculateFriction(float _frictionCoeffient, float _normalForce) {
	float _friction;
	_friction = _frictionCoeffient * _normalForce;
	return _friction;
}

float PhysicsObject::CalculateNormalForce(float _mass) {
	float _normalForce;
	_normalForce = _mass * GravitationalForce;
	return _normalForce;
}

float PhysicsObject::CalculateFrictionCoeffient(float _fMotor, float _normalForce) {
	float _ForceNeededToMove = StaticFrictioncoefficient * _normalForce;
	float _FrictionCoeffient;

	if (_fMotor <= _ForceNeededToMove) {
		_FrictionCoeffient = StaticFrictioncoefficient;
	}
	else {
		_FrictionCoeffient = DynamicFrictioncoefficient;
	}
	return _FrictionCoeffient;
}


float PhysicsObject::CalculateFmotorPlayer() {
	float _ForceAcceleration = 100000.0f;
	float _ForceDecceleration = 200000.0f;
	float _MaxForce = 50000000.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
		if (NewForce < _MaxForce) {
			NewForce = currentForce + _ForceAcceleration;
			currentForce = NewForce;
		}
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
		if (NewForce < _MaxForce) {
			NewForce = currentForce + _ForceAcceleration;
			currentForce = NewForce;
		}

	}

	else {

		if (currentForce > 0) {
			NewForce = currentForce - _ForceDecceleration;
			currentForce = NewForce;
		}

	}

	return NewForce;
}

float PhysicsObject::CalculateFmotorEnemy() {
	float _maxForce = 50000000.0f;
	float  _ForceAcceleration = 100000.0f;

	if (NewForce < _maxForce) {
		NewForce = currentForce + _ForceAcceleration;
		currentForce = NewForce;
	}

	return NewForce;
}

void PhysicsObject::ShowInformation() {
	std::cout << "deltaTime" << DeltaTime << std::endl;
	std::cout << "GravitationalForce" << GravitationalForce << std::endl;
	std::cout << "Fmotor : " << Fmotor << std::endl;
	std::cout << "NormalForce : " << NormalForce << std::endl;
	std::cout << "FrictionCoeffient : " << FrictionCoeffient << std::endl;
	std::cout << "Friction : " << Friction << std::endl;
	std::cout << "Fnetto : " << Fnetto << std::endl;
	std::cout << "Acceleration : " << Acceleration << std::endl;
	std::cout << "Velocity : " << Velocity << std::endl;
	std::cout << "Displacement : " << Displacement << std::endl;
}



