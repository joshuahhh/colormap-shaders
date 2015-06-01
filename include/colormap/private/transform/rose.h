/**
 * This file was automatically created with "create_c++_header.sh".
 * Do not edit manually.
 */
#pragma once
#include "../../colormap.h"

namespace colormap
{
namespace transform
{

class Rose : public Colormap
{
private:
	class Wrapper : public WrapperBase
	{
	public:
		#include "../../../../shaders/transform_rose.frag"
	};

public:
	Color getColor(float x) const override
	{
		Wrapper w;
		vec4 c = w.colormap(x);
		Color result;
		result.r = std::max(0.0f, std::min(1.0f, c.r));
		result.g = std::max(0.0f, std::min(1.0f, c.g));
		result.b = std::max(0.0f, std::min(1.0f, c.b));
		result.a = std::max(0.0f, std::min(1.0f, c.a));
		return result;
	}

	std::string getTitle() const override
	{
		return std::string("rose");
	}

	std::string getCategory() const override
	{
		return std::string("transform");
	}

	std::string getSource() const override
	{
		return std::string(
			"float colormap_red(float x) {\n"
			"    if (x < 0.0) {\n"
			"        return 54.0 / 255.0;\n"
			"    } else if (x < 20049.0 / 82979.0) {\n"
			"        return (829.79 * x + 54.51) / 255.0;\n"
			"    } else {\n"
			"        return 1.0;\n"
			"    }\n"
			"}\n"
			"\n"
			"float colormap_green(float x) {\n"
			"    if (x < 20049.0 / 82979.0) {\n"
			"        return 0.0;\n"
			"    } else if (x < 327013.0 / 810990.0) {\n"
			"        return (8546482679670.0 / 10875673217.0 * x - 2064961390770.0 / 10875673217.0) / 255.0;\n"
			"    } else if (x <= 1.0) {\n"
			"        return (103806720.0 / 483977.0 * x + 19607415.0 / 483977.0) / 255.0;\n"
			"    } else {\n"
			"        return 1.0;\n"
			"    }\n"
			"}\n"
			"\n"
			"float colormap_blue(float x) {\n"
			"    if (x < 0.0) {\n"
			"        return 54.0 / 255.0;\n"
			"    } else if (x < 7249.0 / 82979.0) {\n"
			"        return (829.79 * x + 54.51) / 255.0;\n"
			"    } else if (x < 20049.0 / 82979.0) {\n"
			"        return 127.0 / 255.0;\n"
			"    } else if (x < 327013.0 / 810990.0) {\n"
			"        return (792.02249341361393720147485376583 * x - 64.364790735602331034989206222672) / 255.0;\n"
			"    } else {\n"
			"        return 1.0;\n"
			"    }\n"
			"}\n"
			"\n"
			"vec4 colormap(float x) {\n"
			"    return vec4(colormap_red(x), colormap_green(x), colormap_blue(x), 1.0);\n"
			"}\n"
		);
	}
};

} // namespace transform
} // namespace colormap