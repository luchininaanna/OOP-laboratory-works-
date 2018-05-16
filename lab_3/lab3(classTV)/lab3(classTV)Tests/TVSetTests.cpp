#include "stdafx.h"
#include "../lab3(classTV)/TVSet.h"


/*
Телевизор
изначально выключен
*/

struct TVSetFixture
{
	CTVSet tv;
};

// Телевизор 
BOOST_FIXTURE_TEST_SUITE(TVSet, TVSetFixture)
// изначально выключен
BOOST_AUTO_TEST_CASE(is_turned_off_by_default)
{
	BOOST_CHECK(!tv.IsTurnedOn());
}
// не может переключать канал в выключенном состоянии
BOOST_AUTO_TEST_CASE(cant_select_channel_when_turned_off)
{
	BOOST_CHECK(!tv.SelectChannel(87));
	BOOST_CHECK_EQUAL(tv.GetChannel(), 0);
}

//не может выернуться на предыдущий канал 
BOOST_AUTO_TEST_CASE(cant_select_previous_channel_when_turned_off)
{
	BOOST_CHECK(!tv.SelectPreviousChannel());
	BOOST_CHECK_EQUAL(tv.GetChannel(), 0);
}
// может быть включен
BOOST_AUTO_TEST_CASE(can_be_turned_on)
{
	tv.TurnOn();
	BOOST_CHECK(tv.IsTurnedOn());
}
// изначально отображает 0 канал
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

// после включения
BOOST_FIXTURE_TEST_SUITE(when_turned_on, when_turned_on_)

// отображает канал 1
BOOST_AUTO_TEST_CASE(displays_channel_one)
{
	BOOST_CHECK_EQUAL(tv.GetChannel(), 1);
}

// можно выключить
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

// позволяет выбрать канал от 1 до 99
BOOST_AUTO_TEST_CASE(can_select_channel_from_1_to_99)
{
	BOOST_CHECK(tv.SelectChannel(1));
	BOOST_CHECK_EQUAL(tv.GetChannel(), 1);

	BOOST_CHECK(tv.SelectChannel(99));
	BOOST_CHECK_EQUAL(tv.GetChannel(), 99);

	// Выбираем канал между 1 и 99
	BOOST_CHECK(tv.SelectChannel(42));
	BOOST_CHECK_EQUAL(tv.GetChannel(), 42);

	// При попытке выбрать канал за пределами [1; 99] 
	// телевизор не должен менять свой канал
	BOOST_CHECK(!tv.SelectChannel(0));
	BOOST_CHECK_EQUAL(tv.GetChannel(), 42);

	BOOST_CHECK(!tv.SelectChannel(100));
	BOOST_CHECK_EQUAL(tv.GetChannel(), 42);
}

//позволяет выбрать предыдущий канал
BOOST_AUTO_TEST_CASE(can_select_previous_channel)
{
	//выбрали сначала 50 канал,а затем 90
	tv.SelectChannel(50);
	BOOST_CHECK_EQUAL(tv.GetChannel(), 50);
	tv.SelectChannel(90);
	BOOST_CHECK_EQUAL(tv.GetChannel(), 90);

	//возвращаемся на предыдущий канал
	BOOST_CHECK(tv.SelectPreviousChannel());
	BOOST_CHECK_EQUAL(tv.GetChannel(), 50);
}

//проверяем возможность установить имя для канала
BOOST_AUTO_TEST_CASE(can_set_channel_name_)
{
	BOOST_CHECK(tv.SetChannelName(10, "   russian    extreme   "));
}

//пробуем получить номер канала по имени
BOOST_AUTO_TEST_CASE(can_get_channel_by_name_)
{
	BOOST_CHECK(tv.SetChannelName(10, "   russian    extreme   "));

	BOOST_CHECK(tv.SelectChannel("russian extreme"));

	BOOST_CHECK_EQUAL(tv.GetChannelByName("russian extreme"), 10);
}

//пробуем получить имя канала по номеру
BOOST_AUTO_TEST_CASE(can_get_channel_name_by_channel_)
{
	BOOST_CHECK(tv.SetChannelName(10, "   russian    extreme   "));

	BOOST_CHECK(tv.SelectChannel("russian extreme"));

	BOOST_CHECK_EQUAL(tv.GetChannelName(10), "russian extreme");

}

//пробуем получить информацию по удаленному каналу
BOOST_AUTO_TEST_CASE(can_not_get_channel_when_channel_name_was_deleted_)
{
	BOOST_CHECK(tv.SetChannelName(10, "   russian    extreme   "));

	BOOST_CHECK(tv.SelectChannel("russian extreme"));

	tv.DeleteChannelName("russian extreme");

	BOOST_CHECK_EQUAL(tv.GetChannelByName("russian extreme"), 0);
}

//пробуем получить информацию для выключенного телевизора (номер канала по имени)
BOOST_AUTO_TEST_CASE(can_not_get_channel_when_TVSet_was_turned_off_)
{
	BOOST_CHECK(tv.SetChannelName(10, "   russian    extreme   "));

	BOOST_CHECK(tv.SelectChannel("russian extreme"));

	tv.TurnOff();

	BOOST_CHECK_EQUAL(tv.GetChannelByName("russian extreme"), 0);
}

//пробуем получить информацию для выключенного телевизора (имя канала по номеру)
BOOST_AUTO_TEST_CASE(can_not_delete_channel_name_when_TVSet_was_turned_off_)
{
	BOOST_CHECK(tv.SetChannelName(10, "   russian    extreme   "));

	BOOST_CHECK(tv.SelectChannel("russian extreme"));

	tv.TurnOff();

	BOOST_CHECK_EQUAL(tv.GetChannelName(10), "");
}

//проверяем возможность переустановить имя для канала
BOOST_AUTO_TEST_CASE(can_reset_channel_name_)
{
	BOOST_CHECK(tv.SetChannelName(10, "   russian    extreme   "));
	BOOST_CHECK(tv.SetChannelName(10, "   russian   "));
}

//проверяем возможность обратиться к каналу по переустановленному уровню
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

// после повторного включения
BOOST_FIXTURE_TEST_SUITE(after_subsequent_turning_on, after_subsequent_turning_on_)

// восстанавливает последний выбранный канал
BOOST_AUTO_TEST_CASE(restores_last_selected_channel)
{
	BOOST_CHECK_EQUAL(tv.GetChannel(), 35);
}

BOOST_AUTO_TEST_CASE(restores_previous_selected_channel)
{
	//выбрали сначала 50 канал,а затем хотим вернуться на 33, который был до выключения
	tv.SelectChannel(50);

	//возвращаемся на предыдущий канал
	BOOST_CHECK(tv.SelectPreviousChannel());
	BOOST_CHECK_EQUAL(tv.GetChannel(), 35);
}

BOOST_AUTO_TEST_SUITE_END()

// после повторного включения
BOOST_FIXTURE_TEST_SUITE(set_name_for_channel, after_subsequent_turning_on_)

BOOST_AUTO_TEST_SUITE_END()


// Напишите тесты для недостающего функционала класса CTVSet (если нужно)
//	и для дополнительных заданий на бонусные баллы (если нужно)
// После написания каждого теста убедитесь, что он не проходит.
// Доработайте простейшим образом класс CTVSet, чтобы этот тест и предыдущие проходили
// При необходимости выполните рефакторинг кода, сохраняя работоспособность тестов
// При необходимости используйте вложенные тесты (как использующие fixture, так и нет)
// Имена тестам и test suite-ам давайте такие, чтобы выводимая в output иерархия
//	тестов читалась как спецификация на английском языке, описывающая поведение телевизора

BOOST_AUTO_TEST_SUITE_END()