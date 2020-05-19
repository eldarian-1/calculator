#pragma once

#using <system.dll>

using namespace System;

namespace Window
{

	ref class Transaction
	{
	private:
		String^ from;
		String^ to;
		Double^ summ;
		Double^ tariph;
		DateTime^ dateTime;

	public:
		Transaction(String^ f, String^ t, Double^ s, Double^ tr)
			: from(f), to(t), summ(s), tariph(tr), dateTime(DateTime::Now) {}

		String^ ToString() override
		{
			return dateTime + ": Был совершен перевод " + summ + " " + from + " в " + Math::Round(*summ/(*tariph), 2) + " "+ to + " по тарифу 1 " + to + " = " + tariph + " " + from + ".";
		}

	};

}