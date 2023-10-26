#pragma once

#include <string>
#include <string_view>
#include <optional>

/**
* Chapter 1. Exercise 1-5, 1-6
*/
class AirlineTicket
{
	
	std::string m_passengerName {"Unknown Passenger"};
	int m_numberOfMiles {0};
	bool m_hasEliteSuperRewardsStatus {false};

	std::optional<unsigned int> m_frequentFlyerNumber {std::nullopt};

public:

	AirlineTicket();
	AirlineTicket(std::string_view name, int numberOfMiles, bool hasEliteSuperRewardsStatus);
	AirlineTicket(const AirlineTicket& other);
	AirlineTicket& operator= (const AirlineTicket& other) = default;
	AirlineTicket(AirlineTicket&& other) = default;
	AirlineTicket& operator= (AirlineTicket&& other) = default;
	virtual ~AirlineTicket() = default;

	double calculatePriceInDollars() const;

	std::string getPassengerName() const;
	void setPassengerName(const std::string& name);

	int getNumberOfMiles() const;
	void setNumberOfMiles(int miles);

	bool hasEliteSuperRewardStatus() const;
	void setHasEliteSuperRewardStatus(bool status);

	std::optional<unsigned int> getFrequentFlyerNumber() const;
	void setFrequentFlyerNumber(unsigned int number);
};