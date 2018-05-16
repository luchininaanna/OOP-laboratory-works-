#include "stdafx.h"
#include "../lab3(classTV)/TVSet.h"


/*
���������
���������� ��������
*/

struct TVSetFixture
{
	CTVSet tv;
};

// ��������� 
BOOST_FIXTURE_TEST_SUITE(TVSet, TVSetFixture)
// ���������� ��������
BOOST_AUTO_TEST_CASE(is_turned_off_by_default)
{
	BOOST_CHECK(!tv.IsTurnedOn());
}
// �� ����� ����������� ����� � ����������� ���������
BOOST_AUTO_TEST_CASE(cant_select_channel_when_turned_off)
{
	BOOST_CHECK(!tv.SelectChannel(87));
	BOOST_CHECK_EQUAL(tv.GetChannel(), 0);
}

//�� ����� ���������� �� ���������� ����� 
BOOST_AUTO_TEST_CASE(cant_select_previous_channel_when_turned_off)
{
	BOOST_CHECK(!tv.SelectPreviousChannel());
	BOOST_CHECK_EQUAL(tv.GetChannel(), 0);
}
// ����� ���� �������
BOOST_AUTO_TEST_CASE(can_be_turned_on)
{
	tv.TurnOn();
	BOOST_CHECK(tv.IsTurnedOn());
}
// ���������� ���������� 0 �����
BOOST_AUTO_TEST_CASE(displays_channel_0_by_default)
{
	BOOST_CHECK_EQUAL(tv.GetChannel(), 0);
}

struct when_turned_on_ : TVSetFixture
{
	when_turned_on_()
	{
		tv.TurnOn();
	}
};

// ����� ���������
BOOST_FIXTURE_TEST_SUITE(when_turned_on, when_turned_on_)

// ���������� ����� 1
BOOST_AUTO_TEST_CASE(displays_channel_one)
{
	BOOST_CHECK_EQUAL(tv.GetChannel(), 1);
}

// ����� ���������
BOOST_AUTO_TEST_CASE(can_be_turned_off)
{
	tv.TurnOff();
	BOOST_CHECK(!tv.IsTurnedOn());
}

BOOST_AUTO_TEST_CASE(dont_select_previous_channel_if_first_turn_on)
{
	BOOST_CHECK(tv.SelectPreviousChannel());
	BOOST_CHECK_EQUAL(tv.GetChannel(), 1);
}

// ��������� ������� ����� �� 1 �� 99
BOOST_AUTO_TEST_CASE(can_select_channel_from_1_to_99)
{
	BOOST_CHECK(tv.SelectChannel(1));
	BOOST_CHECK_EQUAL(tv.GetChannel(), 1);

	BOOST_CHECK(tv.SelectChannel(99));
	BOOST_CHECK_EQUAL(tv.GetChannel(), 99);

	// �������� ����� ����� 1 � 99
	BOOST_CHECK(tv.SelectChannel(42));
	BOOST_CHECK_EQUAL(tv.GetChannel(), 42);

	// ��� ������� ������� ����� �� ��������� [1; 99] 
	// ��������� �� ������ ������ ���� �����
	BOOST_CHECK(!tv.SelectChannel(0));
	BOOST_CHECK_EQUAL(tv.GetChannel(), 42);

	BOOST_CHECK(!tv.SelectChannel(100));
	BOOST_CHECK_EQUAL(tv.GetChannel(), 42);
}

//��������� ������� ���������� �����
BOOST_AUTO_TEST_CASE(can_select_previous_channel)
{
	//������� ������� 50 �����,� ����� 90
	tv.SelectChannel(50);
	BOOST_CHECK_EQUAL(tv.GetChannel(), 50);
	tv.SelectChannel(90);
	BOOST_CHECK_EQUAL(tv.GetChannel(), 90);

	//������������ �� ���������� �����
	BOOST_CHECK(tv.SelectPreviousChannel());
	BOOST_CHECK_EQUAL(tv.GetChannel(), 50);
}

//��������� ����������� ���������� ��� ��� ������
BOOST_AUTO_TEST_CASE(can_set_channel_name_)
{
	BOOST_CHECK(tv.SetChannelName(10, "   russian    extreme   "));
}

//������� �������� ����� ������ �� �����
BOOST_AUTO_TEST_CASE(can_get_channel_by_name_)
{
	BOOST_CHECK(tv.SetChannelName(10, "   russian    extreme   "));

	BOOST_CHECK(tv.SelectChannel("russian extreme"));

	BOOST_CHECK_EQUAL(tv.GetChannelByName("russian extreme"), 10);
}

//������� �������� ��� ������ �� ������
BOOST_AUTO_TEST_CASE(can_get_channel_name_by_channel_)
{
	BOOST_CHECK(tv.SetChannelName(10, "   russian    extreme   "));

	BOOST_CHECK(tv.SelectChannel("russian extreme"));

	BOOST_CHECK_EQUAL(tv.GetChannelName(10), "russian extreme");

}

//������� �������� ���������� �� ���������� ������
BOOST_AUTO_TEST_CASE(can_not_get_channel_when_channel_name_was_deleted_)
{
	BOOST_CHECK(tv.SetChannelName(10, "   russian    extreme   "));

	BOOST_CHECK(tv.SelectChannel("russian extreme"));

	tv.DeleteChannelName("russian extreme");

	BOOST_CHECK_EQUAL(tv.GetChannelByName("russian extreme"), 0);
}

//������� �������� ���������� ��� ������������ ���������� (����� ������ �� �����)
BOOST_AUTO_TEST_CASE(can_not_get_channel_when_TVSet_was_turned_off_)
{
	BOOST_CHECK(tv.SetChannelName(10, "   russian    extreme   "));

	BOOST_CHECK(tv.SelectChannel("russian extreme"));

	tv.TurnOff();

	BOOST_CHECK_EQUAL(tv.GetChannelByName("russian extreme"), 0);
}

//������� �������� ���������� ��� ������������ ���������� (��� ������ �� ������)
BOOST_AUTO_TEST_CASE(can_not_delete_channel_name_when_TVSet_was_turned_off_)
{
	BOOST_CHECK(tv.SetChannelName(10, "   russian    extreme   "));

	BOOST_CHECK(tv.SelectChannel("russian extreme"));

	tv.TurnOff();

	BOOST_CHECK_EQUAL(tv.GetChannelName(10), "");
}

//��������� ����������� �������������� ��� ��� ������
BOOST_AUTO_TEST_CASE(can_reset_channel_name_)
{
	BOOST_CHECK(tv.SetChannelName(10, "   russian    extreme   "));
	BOOST_CHECK(tv.SetChannelName(10, "   russian   "));
}

//��������� ����������� ���������� � ������ �� ������������������ ������
BOOST_AUTO_TEST_CASE(can_get_channel_by_reset_name_)
{
	BOOST_CHECK(tv.SetChannelName(10, "   russian    extreme   "));
	BOOST_CHECK(tv.SetChannelName(10, "   russian   "));

	BOOST_CHECK_EQUAL(tv.GetChannelName(10), "russian");
}

BOOST_AUTO_TEST_SUITE_END()

struct after_subsequent_turning_on_ : when_turned_on_
{
	after_subsequent_turning_on_()
	{
		tv.SelectChannel(35);
		tv.TurnOff();
		tv.TurnOn();
	}
};

// ����� ���������� ���������
BOOST_FIXTURE_TEST_SUITE(after_subsequent_turning_on, after_subsequent_turning_on_)

// ��������������� ��������� ��������� �����
BOOST_AUTO_TEST_CASE(restores_last_selected_channel)
{
	BOOST_CHECK_EQUAL(tv.GetChannel(), 35);
}

BOOST_AUTO_TEST_CASE(restores_previous_selected_channel)
{
	//������� ������� 50 �����,� ����� ����� ��������� �� 33, ������� ��� �� ����������
	tv.SelectChannel(50);

	//������������ �� ���������� �����
	BOOST_CHECK(tv.SelectPreviousChannel());
	BOOST_CHECK_EQUAL(tv.GetChannel(), 35);
}

BOOST_AUTO_TEST_SUITE_END()

// ����� ���������� ���������
BOOST_FIXTURE_TEST_SUITE(set_name_for_channel, after_subsequent_turning_on_)

BOOST_AUTO_TEST_SUITE_END()


// �������� ����� ��� ������������ ����������� ������ CTVSet (���� �����)
//	� ��� �������������� ������� �� �������� ����� (���� �����)
// ����� ��������� ������� ����� ���������, ��� �� �� ��������.
// ����������� ���������� ������� ����� CTVSet, ����� ���� ���� � ���������� ���������
// ��� ������������� ��������� ����������� ����, �������� ����������������� ������
// ��� ������������� ����������� ��������� ����� (��� ������������ fixture, ��� � ���)
// ����� ������ � test suite-�� ������� �����, ����� ��������� � output ��������
//	������ �������� ��� ������������ �� ���������� �����, ����������� ��������� ����������

BOOST_AUTO_TEST_SUITE_END()