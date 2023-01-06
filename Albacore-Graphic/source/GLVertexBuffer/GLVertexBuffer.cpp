/*
 * Jinseok Son
 * CS200
 * Fall 2022

*/

#include<GLVertexBuffer/GLVertexBuffer.h>


GLVertexBuffer::GLVertexBuffer(GLsizei size_in_bytes)
{
	glCreateBuffers(1, &buffer_handle);
	glNamedBufferStorage(buffer_handle, size_in_bytes, nullptr, GL_DYNAMIC_STORAGE_BIT);
	size = size_in_bytes;

}

GLVertexBuffer::~GLVertexBuffer()
{
	glDeleteBuffers(1,&buffer_handle);
}

GLVertexBuffer::GLVertexBuffer(GLVertexBuffer&& temp) noexcept
{
	std::swap(buffer_handle,temp.buffer_handle);
	
}

GLVertexBuffer& GLVertexBuffer::operator=(GLVertexBuffer&& temp) noexcept
{
	//need delete 
	std::swap(buffer_handle, temp.buffer_handle);
	return *this;
}

void GLVertexBuffer::Use(bool bind) const
{
	if (bind == true)
	{
		glBindBuffer(GL_ARRAY_BUFFER, buffer_handle);
	}

	if (bind == false)
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}

void GLVertexBuffer::send_buffer_data_to_gpu (const void* data, GLsizei size_bytes, GLsizei starting_offset) const
{
	glNamedBufferSubData(buffer_handle, starting_offset, size_bytes, data);
}