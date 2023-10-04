#include "AirlineTicket.h"

AirlineTicket::AirlineTicket()
{
}

AirlineTicket::AirlineTicket(const std::string& name, int numberOfMiles, bool hasEliteSuperRewardsStatus)
	: m_passengerName{name}, 
	m_numberOfMiles{numberOfMiles}, 
	m_hasEliteSuperRewardsStatus{hasEliteSuperRewardsStatus}
{
}

AirlineTicket::AirlineTicket(const AirlineTicket& other)
{
	m_passengerName = other.m_passengerName;
	m_numberOfMiles = other.m_numberOfMiles;
	m_hasEliteSuperRewardsStatus = other.m_hasEliteSuperRewardsStatus;
}

AirlineTicket::~AirlineTicket()
{
}

double AirlineTicket::calculatePriceInDollars()
{
	return 0.0;
}

std::string AirlineTicket::getPassengerName() const
{
	return m_passengerName;
}

void AirlineTicket::setPassengerName(const std::string& name)
{
	m_passengerName = name;
}

int AirlineTicket::getNumberOfMiles() const
{
	return m_numberOfMiles;
}

void AirlineTicket::setNumberOfMiles(int miles)
{
	m_numberOfMiles = miles;
}

bool AirlineTicket::hasEliteSuperRewardStatus() const
{
	return m_hasEliteSuperRewardsStatus;
}

void AirlineTicket::setHasEliteSuperRewardStatus(bool status)
{
	m_hasEliteSuperRewardsStatus = status;
}

std::optional<unsigned int> AirlineTicket::getFrequentFlyerNumber()
{
	return m_frequentFlyerNumber;
}

void AirlineTicket::setFrequentFlyerNumber(unsigned int number)
{
	m_frequentFlyerNumber = std::optional<unsigned int>(number);
}
