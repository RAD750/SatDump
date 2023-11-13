#include "imgui/imgui_image.h"
#include "gl3w/gl3w.h"
#include "logger.h"

void funcUpdateMMImageTexture(unsigned int gl_text, uint32_t* buffer, int width, int height)
{
    glBindTexture(GL_TEXTURE_2D, gl_text);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void bindMMImageTextureFunctions()
{
    if (gl3wInit())
    {
        logger->critical("Could not init gl3w! Exiting");
        exit(1);
    }
    updateMMImageTexture = funcUpdateMMImageTexture;
}